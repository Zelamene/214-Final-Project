import React, { useState, useEffect } from 'react';
import { Leaf, ShoppingCart, Users, Package, TrendingUp, AlertCircle, CheckCircle, Flower2, Trees, Plus, CreditCard, Smartphone, DollarSign } from 'lucide-react';

const API_URL = 'http://localhost:8080/api';

const NurseryDashboard = () => {
  const [activeTab, setActiveTab] = useState('dashboard');
  const [plants, setPlants] = useState({ plant_count: 0 });
  const [inventory, setInventory] = useState({ items: [], total_plants: 0 });
  const [customers, setCustomers] = useState([]);
  const [currentCustomer, setCurrentCustomer] = useState(null);
  const [currentOrder, setCurrentOrder] = useState(null);
  const [notifications, setNotifications] = useState([]);
  const [loading, setLoading] = useState(false);

  const [flowerForm, setFlowerForm] = useState({ type: 'low', price: '', color: '', container: 'Wood' });
  const [treeForm, setTreeForm] = useState({ type: 'low', price: '', height: '', container: 'Plastic' });
  const [customerName, setCustomerName] = useState('');

  useEffect(() => {
    fetchDashboardData();
  }, []);

  const fetchDashboardData = async () => {
    try {
      const [plantsRes, inventoryRes] = await Promise.all([
        fetch(`${API_URL}/plants`),
        fetch(`${API_URL}/inventory`)
      ]);
      
      if (plantsRes.ok) setPlants(await plantsRes.json());
      if (inventoryRes.ok) setInventory(await inventoryRes.json());
    } catch (error) {
      addNotification('Failed to fetch data', 'error');
    }
  };

  const addNotification = (message, type = 'success') => {
    const id = Date.now();
    setNotifications(prev => [...prev, { id, message, type }]);
    setTimeout(() => {
      setNotifications(prev => prev.filter(n => n.id !== id));
    }, 4000);
  };

  const runQuickDemo = async () => {
    setLoading(true);
    try {
      const res = await fetch(`${API_URL}/demo/quick`, { method: 'POST' });
      const data = await res.json();
      if (data.status === 'success') {
        addNotification(`Demo completed! ${data.plants_added} plants added and grown.`);
        fetchDashboardData();
      }
    } catch (error) {
      addNotification('Failed to run demo', 'error');
    }
    setLoading(false);
  };

  const addPlant = async (type, plantData) => {
    setLoading(true);
    try {
      const res = await fetch(`${API_URL}/plants/${type}`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(plantData)
      });
      const data = await res.json();
      if (data.status === 'success') {
        addNotification(`${type === 'flower' ? 'Flower' : 'Tree'} added successfully!`);
        fetchDashboardData();
        if (type === 'flower') {
          setFlowerForm({ type: 'low', price: '', color: '', container: 'Wood' });
        } else {
          setTreeForm({ type: 'low', price: '', height: '', container: 'Plastic' });
        }
      }
    } catch (error) {
      addNotification('Failed to add plant', 'error');
    }
    setLoading(false);
  };

  const growPlants = async () => {
    setLoading(true);
    try {
      const res = await fetch(`${API_URL}/plants/grow`, { method: 'POST' });
      const data = await res.json();
      if (data.status === 'success') {
        addNotification(`${data.plants_grown} plants grown to maturity!`);
        fetchDashboardData();
      }
    } catch (error) {
      addNotification('Failed to grow plants', 'error');
    }
    setLoading(false);
  };

  const registerCustomer = async () => {
    if (!customerName.trim()) return;
    setLoading(true);
    try {
      const customerId = `customer_${Date.now()}`;
      const res = await fetch(`${API_URL}/customers`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ name: customerName, id: customerId })
      });
      const data = await res.json();
      if (data.status === 'success') {
        setCurrentCustomer({ name: customerName, id: customerId });
        setCustomers(prev => [...prev, { name: customerName, id: customerId }]);
        addNotification(`Welcome, ${customerName}!`);
        setCustomerName('');
      }
    } catch (error) {
      addNotification('Failed to register customer', 'error');
    }
    setLoading(false);
  };

  const createOrder = async () => {
    if (!currentCustomer) {
      addNotification('Please register as a customer first', 'error');
      return;
    }
    setLoading(true);
    try {
      const res = await fetch(`${API_URL}/orders`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ customer_id: currentCustomer.id })
      });
      const data = await res.json();
      if (data.status === 'success') {
        setCurrentOrder({ id: data.order_id, items: [], total: 0 });
        addNotification('Order created!');
      }
    } catch (error) {
      addNotification('Failed to create order', 'error');
    }
    setLoading(false);
  };

  const StatCard = ({ icon: Icon, label, value, color }) => (
    <div className="bg-white rounded-xl p-6 shadow-lg border border-gray-100 hover:shadow-xl transition-shadow">
      <div className="flex items-center justify-between">
        <div>
          <p className="text-gray-500 text-sm font-medium mb-1">{label}</p>
          <p className="text-3xl font-bold text-gray-800">{value}</p>
        </div>
        <div className={`${color} p-4 rounded-full`}>
          <Icon className="text-white" size={24} />
        </div>
      </div>
    </div>
  );

  return (
    <div className="min-h-screen bg-gradient-to-br from-green-50 via-emerald-50 to-teal-50">
      {/* Notifications */}
      <div className="fixed top-4 right-4 z-50 space-y-2">
        {notifications.map(notif => (
          <div
            key={notif.id}
            className={`flex items-center gap-2 px-4 py-3 rounded-lg shadow-lg ${
              notif.type === 'success' ? 'bg-green-500' : 'bg-red-500'
            } text-white animate-slide-in`}
          >
            {notif.type === 'success' ? <CheckCircle size={20} /> : <AlertCircle size={20} />}
            <span className="font-medium">{notif.message}</span>
          </div>
        ))}
      </div>

      {/* Header */}
      <div className="bg-white shadow-md border-b border-gray-200">
        <div className="max-w-7xl mx-auto px-6 py-4">
          <div className="flex items-center justify-between">
            <div className="flex items-center gap-3">
              <div className="bg-gradient-to-br from-green-500 to-emerald-600 p-3 rounded-xl">
                <Leaf className="text-white" size={28} />
              </div>
              <div>
                <h1 className="text-2xl font-bold text-gray-800">Nursery Management</h1>
                <p className="text-sm text-gray-500">Design Patterns in Action</p>
              </div>
            </div>
            <button
              onClick={runQuickDemo}
              disabled={loading}
              className="bg-gradient-to-r from-purple-500 to-pink-600 text-white px-6 py-2 rounded-lg font-semibold hover:from-purple-600 hover:to-pink-700 transition-all disabled:opacity-50 flex items-center gap-2"
            >
              <TrendingUp size={18} />
              Run Quick Demo
            </button>
          </div>
        </div>
      </div>

      {/* Navigation Tabs */}
      <div className="bg-white shadow-sm border-b border-gray-200">
        <div className="max-w-7xl mx-auto px-6">
          <div className="flex gap-6">
            {[
              { id: 'dashboard', label: 'Dashboard', icon: TrendingUp },
              { id: 'plants', label: 'Manage Plants', icon: Leaf },
              { id: 'customers', label: 'Customers', icon: Users },
              { id: 'orders', label: 'Orders', icon: ShoppingCart }
            ].map(tab => (
              <button
                key={tab.id}
                onClick={() => setActiveTab(tab.id)}
                className={`flex items-center gap-2 px-4 py-4 border-b-2 transition-colors ${
                  activeTab === tab.id
                    ? 'border-green-500 text-green-600'
                    : 'border-transparent text-gray-600 hover:text-gray-800'
                }`}
              >
                <tab.icon size={18} />
                <span className="font-medium">{tab.label}</span>
              </button>
            ))}
          </div>
        </div>
      </div>

      {/* Main Content */}
      <div className="max-w-7xl mx-auto px-6 py-8">
        {activeTab === 'dashboard' && (
          <div className="space-y-6">
            <div className="grid grid-cols-1 md:grid-cols-3 gap-6">
              <StatCard
                icon={Leaf}
                label="Total Plants"
                value={plants.plant_count || 0}
                color="bg-gradient-to-br from-green-500 to-emerald-600"
              />
              <StatCard
                icon={Package}
                label="Inventory Items"
                value={inventory.total_plants || 0}
                color="bg-gradient-to-br from-blue-500 to-indigo-600"
              />
              <StatCard
                icon={Users}
                label="Registered Customers"
                value={customers.length}
                color="bg-gradient-to-br from-purple-500 to-pink-600"
              />
            </div>

            <div className="bg-white rounded-xl p-6 shadow-lg border border-gray-100">
              <h3 className="text-xl font-bold text-gray-800 mb-4">Quick Actions</h3>
              <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
                <button
                  onClick={growPlants}
                  disabled={loading}
                  className="bg-gradient-to-r from-green-500 to-emerald-600 text-white p-4 rounded-lg font-semibold hover:from-green-600 hover:to-emerald-700 transition-all disabled:opacity-50 flex items-center justify-center gap-2"
                >
                  <Trees size={20} />
                  Grow All Plants
                </button>
                <button
                  onClick={createOrder}
                  disabled={loading || !currentCustomer}
                  className="bg-gradient-to-r from-blue-500 to-indigo-600 text-white p-4 rounded-lg font-semibold hover:from-blue-600 hover:to-indigo-700 transition-all disabled:opacity-50 flex items-center justify-center gap-2"
                >
                  <ShoppingCart size={20} />
                  Create New Order
                </button>
              </div>
            </div>
          </div>
        )}

        {activeTab === 'plants' && (
          <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
            {/* Flower Form */}
            <div className="bg-white rounded-xl p-6 shadow-lg border border-gray-100">
              <h3 className="text-xl font-bold text-gray-800 mb-4 flex items-center gap-2">
                <Flower2 className="text-pink-500" />
                Add Flowering Plant
              </h3>
              
              <div className="space-y-4">
                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">Maintenance Type</label>
                  <select 
                    value={flowerForm.type}
                    onChange={(e) => setFlowerForm({...flowerForm, type: e.target.value})}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
                  >
                    <option value="low">Low Maintenance (Rose)</option>
                    <option value="high">High Maintenance (Cherry Blossom)</option>
                  </select>
                </div>

                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">Color</label>
                  <input
                    type="text"
                    value={flowerForm.color}
                    onChange={(e) => setFlowerForm({...flowerForm, color: e.target.value})}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
                    placeholder="e.g., Red, Pink, Yellow"
                  />
                </div>

                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">Price (R)</label>
                  <input
                    type="number"
                    step="0.01"
                    value={flowerForm.price}
                    onChange={(e) => setFlowerForm({...flowerForm, price: e.target.value})}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
                    placeholder="e.g., 45.00"
                  />
                </div>

                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">Container</label>
                  <select 
                    value={flowerForm.container}
                    onChange={(e) => setFlowerForm({...flowerForm, container: e.target.value})}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
                  >
                    <option value="Wood">Wood</option>
                    <option value="Cedar">Cedar</option>
                    <option value="Plastic">Plastic</option>
                    <option value="Large Wood">Large Wood</option>
                  </select>
                </div>

                <button
                  onClick={() => addPlant('flower', { ...flowerForm, price: parseFloat(flowerForm.price) })}
                  disabled={loading || !flowerForm.color || !flowerForm.price}
                  className="w-full bg-gradient-to-r from-green-500 to-emerald-600 text-white py-3 rounded-lg font-semibold hover:from-green-600 hover:to-emerald-700 transition-all disabled:opacity-50 flex items-center justify-center gap-2"
                >
                  <Plus size={20} />
                  Add Flower
                </button>
              </div>
            </div>

            {/* Tree Form */}
            <div className="bg-white rounded-xl p-6 shadow-lg border border-gray-100">
              <h3 className="text-xl font-bold text-gray-800 mb-4 flex items-center gap-2">
                <Trees className="text-green-600" />
                Add Tree
              </h3>
              
              <div className="space-y-4">
                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">Maintenance Type</label>
                  <select 
                    value={treeForm.type}
                    onChange={(e) => setTreeForm({...treeForm, type: e.target.value})}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
                  >
                    <option value="low">Low Maintenance (Aloe)</option>
                    <option value="high">High Maintenance (Baobab)</option>
                  </select>
                </div>

                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">Height (meters)</label>
                  <input
                    type="number"
                    step="0.1"
                    value={treeForm.height}
                    onChange={(e) => setTreeForm({...treeForm, height: e.target.value})}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
                    placeholder="e.g., 0.5, 1.2"
                  />
                </div>

                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">Price (R)</label>
                  <input
                    type="number"
                    step="0.01"
                    value={treeForm.price}
                    onChange={(e) => setTreeForm({...treeForm, price: e.target.value})}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
                    placeholder="e.g., 35.00"
                  />
                </div>

                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">Container</label>
                  <select 
                    value={treeForm.container}
                    onChange={(e) => setTreeForm({...treeForm, container: e.target.value})}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
                  >
                    <option value="Wood">Wood</option>
                    <option value="Cedar">Cedar</option>
                    <option value="Plastic">Plastic</option>
                    <option value="Large Wood">Large Wood</option>
                  </select>
                </div>

                <button
                  onClick={() => addPlant('tree', { ...treeForm, height: parseFloat(treeForm.height), price: parseFloat(treeForm.price) })}
                  disabled={loading || !treeForm.height || !treeForm.price}
                  className="w-full bg-gradient-to-r from-green-500 to-emerald-600 text-white py-3 rounded-lg font-semibold hover:from-green-600 hover:to-emerald-700 transition-all disabled:opacity-50 flex items-center justify-center gap-2"
                >
                  <Plus size={20} />
                  Add Tree
                </button>
              </div>
            </div>
          </div>
        )}

        {activeTab === 'customers' && (
          <div className="max-w-2xl mx-auto">
            <div className="bg-white rounded-xl p-6 shadow-lg border border-gray-100">
              <h3 className="text-xl font-bold text-gray-800 mb-4 flex items-center gap-2">
                <Users className="text-blue-500" />
                Customer Registration
              </h3>
              
              {currentCustomer ? (
                <div className="bg-green-50 border border-green-200 rounded-lg p-4">
                  <p className="text-green-800 font-semibold">Registered as: {currentCustomer.name}</p>
                  <p className="text-green-600 text-sm">ID: {currentCustomer.id}</p>
                  <button
                    onClick={() => setCurrentCustomer(null)}
                    className="mt-3 text-sm text-green-700 underline"
                  >
                    Register as different customer
                  </button>
                </div>
              ) : (
                <div>
                  <input
                    type="text"
                    value={customerName}
                    onChange={(e) => setCustomerName(e.target.value)}
                    placeholder="Enter your name"
                    className="w-full px-4 py-3 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 focus:border-transparent mb-4"
                  />
                  <button
                    onClick={registerCustomer}
                    disabled={loading || !customerName.trim()}
                    className="w-full bg-gradient-to-r from-blue-500 to-indigo-600 text-white py-3 rounded-lg font-semibold hover:from-blue-600 hover:to-indigo-700 transition-all disabled:opacity-50"
                  >
                    Register
                  </button>
                </div>
              )}
            </div>
            
            {customers.length > 0 && (
              <div className="mt-6 bg-white rounded-xl p-6 shadow-lg border border-gray-100">
                <h3 className="text-xl font-bold text-gray-800 mb-4">Registered Customers</h3>
                <div className="space-y-2">
                  {customers.map(customer => (
                    <div key={customer.id} className="flex items-center justify-between p-3 bg-gray-50 rounded-lg">
                      <span className="font-medium text-gray-800">{customer.name}</span>
                      <span className="text-sm text-gray-500">{customer.id}</span>
                    </div>
                  ))}
                </div>
              </div>
            )}
          </div>
        )}

        {activeTab === 'orders' && (
          <div className="max-w-4xl mx-auto">
            <div className="bg-white rounded-xl p-6 shadow-lg border border-gray-100">
              <h3 className="text-xl font-bold text-gray-800 mb-4">Order Management</h3>
              
              {!currentCustomer ? (
                <div className="text-center py-8">
                  <Users className="mx-auto text-gray-400 mb-4" size={48} />
                  <p className="text-gray-600 mb-4">Please register as a customer first</p>
                  <button
                    onClick={() => setActiveTab('customers')}
                    className="bg-blue-500 text-white px-6 py-2 rounded-lg hover:bg-blue-600 transition-colors"
                  >
                    Go to Customer Registration
                  </button>
                </div>
              ) : !currentOrder ? (
                <div className="text-center py-8">
                  <ShoppingCart className="mx-auto text-gray-400 mb-4" size={48} />
                  <p className="text-gray-600 mb-4">No active order</p>
                  <button
                    onClick={createOrder}
                    disabled={loading}
                    className="bg-green-500 text-white px-6 py-3 rounded-lg hover:bg-green-600 transition-colors disabled:opacity-50"
                  >
                    Create New Order
                  </button>
                </div>
              ) : (
                <div>
                  <div className="bg-green-50 border border-green-200 rounded-lg p-4 mb-4">
                    <p className="text-green-800 font-semibold">Active Order: {currentOrder.id}</p>
                    <p className="text-green-600 text-sm">Customer: {currentCustomer.name}</p>
                  </div>
                  
                  <div className="bg-gray-50 rounded-lg p-8 text-center">
                    <ShoppingCart className="mx-auto text-gray-400 mb-3" size={40} />
                    <p className="text-gray-600 mb-2">Order interface ready!</p>
                    <p className="text-sm text-gray-500">Use the API to add items, decorate plants, and checkout</p>
                  </div>
                </div>
              )}
            </div>
          </div>
        )}
      </div>

      <style>{`
        @keyframes slide-in {
          from {
            transform: translateX(100%);
            opacity: 0;
          }
          to {
            transform: translateX(0);
            opacity: 1;
          }
        }
        .animate-slide-in {
          animation: slide-in 0.3s ease-out;
        }
      `}</style>
    </div>
  );
};

export default NurseryDashboard;