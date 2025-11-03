import React, { useState, useEffect } from 'react';
import { Leaf, ShoppingCart, Users, Package, AlertCircle, CheckCircle, Loader, Plus, Trash2, DollarSign } from 'lucide-react';

const API_BASE = 'http://localhost:8080/api';

const App = () => {
  const [activeTab, setActiveTab] = useState('plants');
  const [plants, setPlants] = useState({ count: 0 });
  const [inventory, setInventory] = useState({ items: [], total_plants: 0 });
  const [customers, setCustomers] = useState([]);
  const [orders, setOrders] = useState({});
  const [notifications, setNotifications] = useState([]);
  const [loading, setLoading] = useState(false);
  const [complaints, setComplaints] = useState([]);

  const addNotification = (message, type = 'success') => {
    const id = Date.now();
    setNotifications(prev => [...prev, { id, message, type }]);
    setTimeout(() => {
      setNotifications(prev => prev.filter(n => n.id !== id));
    }, 4000);
  };

  const fetchData = async () => {
    try {
      const [plantsRes, invRes] = await Promise.all([
        fetch(`${API_BASE}/plants`),
        fetch(`${API_BASE}/inventory`)
      ]);
      
      if (plantsRes.ok) setPlants(await plantsRes.json());
      if (invRes.ok) setInventory(await invRes.json());
    } catch (err) {
      console.error('Fetch error:', err);
    }
  };

  useEffect(() => {
    fetchData();
  }, []);

  return (
    <div className="min-h-screen bg-gradient-to-br from-green-50 via-emerald-50 to-teal-50">
      {/* Notifications */}
      <div className="fixed top-4 right-4 z-50 space-y-2">
        {notifications.map(notif => (
          <div
            key={notif.id}
            className={`flex items-center gap-2 px-4 py-3 rounded-lg shadow-lg backdrop-blur-sm animate-in slide-in-from-right ${
              notif.type === 'success' 
                ? 'bg-green-500/90 text-white' 
                : 'bg-red-500/90 text-white'
            }`}
          >
            {notif.type === 'success' ? <CheckCircle size={18} /> : <AlertCircle size={18} />}
            <span className="font-medium">{notif.message}</span>
          </div>
        ))}
      </div>

      {/* Header */}
      <header className="bg-white/80 backdrop-blur-md shadow-sm border-b border-green-100">
        <div className="max-w-7xl mx-auto px-6 py-4">
          <div className="flex items-center justify-between">
            <div className="flex items-center gap-3">
              <div className="bg-gradient-to-br from-green-500 to-emerald-600 p-2 rounded-xl">
                <Leaf className="text-white" size={28} />
              </div>
              <div>
                <h1 className="text-2xl font-bold bg-gradient-to-r from-green-600 to-emerald-600 bg-clip-text text-transparent">
                  Nursery Management
                </h1>
                <p className="text-sm text-gray-500">Plant inventory & order system</p>
              </div>
            </div>
            <div className="flex items-center gap-4 text-sm">
              <div className="bg-green-100 px-4 py-2 rounded-lg">
                <span className="text-green-700 font-semibold">{plants.plant_count || 0} Plants</span>
              </div>
              <div className="bg-blue-100 px-4 py-2 rounded-lg">
                <span className="text-blue-700 font-semibold">{customers.length} Customers</span>
              </div>
            </div>
          </div>
        </div>
      </header>

      {/* Navigation */}
      <nav className="bg-white/60 backdrop-blur-md border-b border-gray-200">
        <div className="max-w-7xl mx-auto px-6">
          <div className="flex gap-2">
            {[
              { id: 'plants', label: 'Plants', icon: Leaf },
              { id: 'customers', label: 'Customers', icon: Users },
              { id: 'orders', label: 'Orders', icon: ShoppingCart },
              { id: 'complaints', label: 'Complaints', icon: AlertCircle },
              { id: 'demo', label: 'Demo', icon: Package }
            ].map(tab => (
              <button
                key={tab.id}
                onClick={() => setActiveTab(tab.id)}
                className={`flex items-center gap-2 px-6 py-4 font-medium transition-all ${
                  activeTab === tab.id
                    ? 'text-green-600 border-b-2 border-green-600 bg-green-50/50'
                    : 'text-gray-600 hover:text-green-600 hover:bg-green-50/30'
                }`}
              >
                <tab.icon size={18} />
                {tab.label}
              </button>
            ))}
          </div>
        </div>
      </nav>

      {/* Main Content */}
      <main className="max-w-7xl mx-auto px-6 py-8">
        {loading && (
          <div className="flex items-center justify-center py-12">
            <Loader className="animate-spin text-green-600" size={32} />
          </div>
        )}

        {!loading && activeTab === 'plants' && (
          <PlantsTab
            plants={plants}
            inventory={inventory}
            onRefresh={fetchData}
            addNotification={addNotification}
            setLoading={setLoading}
          />
        )}

        {!loading && activeTab === 'customers' && (
          <CustomersTab 
            customers={customers}
            setCustomers={setCustomers}
            addNotification={addNotification}
            setLoading={setLoading}
          />
        )}

        {!loading && activeTab === 'orders' && (
          <OrdersTab 
            customers={customers}
            orders={orders}
            setOrders={setOrders}
            addNotification={addNotification}
            setLoading={setLoading}
          />
        )}

        {!loading && activeTab === 'complaints' && (
          <ComplaintsTab 
            customers={customers}
            complaints={complaints}
            setComplaints={setComplaints}
            addNotification={addNotification}
            setLoading={setLoading}
          />
        )}

        {!loading && activeTab === 'demo' && (
          <DemoTab 
            onRefresh={fetchData}
            addNotification={addNotification}
            setLoading={setLoading}
          />
        )}
      </main>
    </div>
  );
};

const ComplaintsTab = ({ customers, complaints, setComplaints, addNotification, setLoading }) => {
  const [selectedCustomer, setSelectedCustomer] = useState('');
  const [complaintText, setComplaintText] = useState('');

  const fileComplaint = async () => {
    if (!selectedCustomer || !complaintText.trim()) {
      addNotification('Please select customer and enter complaint', 'error');
      return;
    }

    setLoading(true);
    try {
      const res = await fetch(`${API_BASE}/complaints`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ 
          customer_id: selectedCustomer, 
          complaint: complaintText.trim() 
        })
      });

      const data = await res.json();
      if (res.ok) {
        const newComplaint = {
          id: Date.now(),
          customer: customers.find(c => c.id === selectedCustomer)?.name || selectedCustomer,
          text: complaintText.trim(),
          timestamp: new Date().toISOString(),
          refundRequested: data.refund_requested,
          refundProcessed: data.refund_processed || false,
          refundAmount: data.refund_amount || 0
        };
        
        setComplaints(prev => [...prev, newComplaint]);
        
        if (data.refund_processed) {
          addNotification(`Complaint filed and refund of R${data.refund_amount.toFixed(2)} processed!`);
        } else {
          addNotification('Complaint filed successfully');
        }
        
        setComplaintText('');
        setSelectedCustomer('');
      } else {
        addNotification(data.message, 'error');
      }
    } catch (err) {
      addNotification('Failed to file complaint', 'error');
    }
    setLoading(false);
  };

  return (
    <div className="space-y-6">
      <div className="bg-white/80 backdrop-blur-sm rounded-2xl shadow-lg p-6 border border-orange-100">
        <h2 className="text-xl font-bold text-gray-800 mb-4 flex items-center gap-2">
          <AlertCircle className="text-orange-600" />
          File Customer Complaint
        </h2>

        <div className="space-y-4">
          <div>
            <label className="block text-sm font-medium text-gray-700 mb-2">Customer</label>
            <select
              value={selectedCustomer}
              onChange={e => setSelectedCustomer(e.target.value)}
              className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-orange-500 focus:border-transparent"
            >
              <option value="">Select customer...</option>
              {customers.map((c, idx) => (
                <option key={idx} value={c.id}>{c.name} - {c.id}</option>
              ))}
            </select>
          </div>

          <div>
            <label className="block text-sm font-medium text-gray-700 mb-2">Complaint Details</label>
            <textarea
              value={complaintText}
              onChange={e => setComplaintText(e.target.value)}
              placeholder="Describe the issue... (include 'refund' if requesting a refund)"
              rows={4}
              className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-orange-500 focus:border-transparent resize-none"
            />
            <p className="text-xs text-gray-500 mt-2">
              💡 Tip: Include the word "refund" in your complaint to automatically process a refund for the last order
            </p>
          </div>

          <button
            onClick={fileComplaint}
            disabled={!selectedCustomer || !complaintText.trim()}
            className="w-full bg-gradient-to-r from-orange-500 to-red-600 text-white px-6 py-3 rounded-lg font-medium hover:from-orange-600 hover:to-red-700 disabled:opacity-50 disabled:cursor-not-allowed transition-all shadow-md hover:shadow-lg"
          >
            Submit Complaint
          </button>
        </div>
      </div>

      <div className="bg-white/80 backdrop-blur-sm rounded-2xl shadow-lg p-6 border border-gray-100">
        <h3 className="text-lg font-bold text-gray-800 mb-4">Complaint History</h3>
        
        {complaints.length === 0 ? (
          <div className="text-center py-12">
            <CheckCircle className="mx-auto text-green-500 mb-3" size={48} />
            <p className="text-gray-500">No complaints filed yet</p>
            <p className="text-sm text-gray-400 mt-1">All customers are happy! 🌱</p>
          </div>
        ) : (
          <div className="space-y-3">
            {complaints.map((complaint) => (
              <div 
                key={complaint.id} 
                className={`p-4 rounded-lg border-l-4 ${
                  complaint.refundProcessed 
                    ? 'bg-red-50 border-red-500' 
                    : complaint.refundRequested 
                    ? 'bg-yellow-50 border-yellow-500'
                    : 'bg-gray-50 border-gray-300'
                }`}
              >
                <div className="flex justify-between items-start mb-2">
                  <div>
                    <div className="font-semibold text-gray-800">{complaint.customer}</div>
                    <div className="text-xs text-gray-500">
                      {new Date(complaint.timestamp).toLocaleString()}
                    </div>
                  </div>
                  <div className="flex gap-2">
                    {complaint.refundRequested && (
                      <span className="bg-yellow-100 text-yellow-700 px-3 py-1 rounded-full text-xs font-medium">
                        Refund Requested
                      </span>
                    )}
                    {complaint.refundProcessed && (
                      <span className="bg-red-100 text-red-700 px-3 py-1 rounded-full text-xs font-medium">
                        Refunded: R{complaint.refundAmount.toFixed(2)}
                      </span>
                    )}
                  </div>
                </div>
                <p className="text-gray-700 text-sm">{complaint.text}</p>
              </div>
            ))}
          </div>
        )}
      </div>

      <div className="bg-gradient-to-br from-blue-50 to-indigo-50 rounded-2xl shadow-lg p-6 border border-blue-200">
        <h3 className="text-lg font-bold text-blue-900 mb-3 flex items-center gap-2">
          <Package className="text-blue-600" />
          Complaint Handling System
        </h3>
        <div className="grid grid-cols-2 gap-4 text-sm">
          <div>
            <h4 className="font-semibold text-blue-900 mb-2">Chain of Responsibility</h4>
            <ul className="space-y-1 text-gray-700">
              <li>• Cashier Handler (first level)</li>
              <li>• Manager Handler (escalation)</li>
              <li>• Automatic refund processing</li>
              <li>• Slip generation system</li>
            </ul>
          </div>
          <div>
            <h4 className="font-semibold text-blue-900 mb-2">Features</h4>
            <ul className="space-y-1 text-gray-700">
              <li>• Mediator pattern for communication</li>
              <li>• RefundSlip and OrderSlip generation</li>
              <li>• Automated issue tracking</li>
              <li>• Handler escalation chain</li>
            </ul>
          </div>
        </div>
      </div>
    </div>
  );
};

const PlantsTab = ({ plants, inventory, onRefresh, addNotification, setLoading }) => {
  const [formData, setFormData] = useState({
    plantType: 'flower',
    maintenance: 'low',
    price: 50,
    color: 'Red',
    height: 1.0,
    container: 'Wood'
  });

  const addPlant = async () => {
    setLoading(true);
    try {
      const endpoint = formData.plantType === 'flower' ? 'flower' : 'tree';
      const body = formData.plantType === 'flower'
        ? { type: formData.maintenance, price: formData.price, color: formData.color, container: formData.container }
        : { type: formData.maintenance, height: formData.height, price: formData.price, container: formData.container };

      const res = await fetch(`${API_BASE}/plants/${endpoint}`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(body)
      });

      const data = await res.json();
      if (res.ok) {
        addNotification(data.message);
        onRefresh();
      } else {
        addNotification(data.message, 'error');
      }
    } catch (err) {
      addNotification('Failed to add plant', 'error');
    }
    setLoading(false);
  };

  const growPlants = async () => {
    setLoading(true);
    try {
      const res = await fetch(`${API_BASE}/plants/grow`, { method: 'POST' });
      const data = await res.json();
      if (res.ok) {
        addNotification(`${data.plants_grown} plants grown to maturity!`);
        onRefresh();
      } else {
        addNotification(data.message, 'error');
      }
    } catch (err) {
      addNotification('Failed to grow plants', 'error');
    }
    setLoading(false);
  };

  const deletePlant = async (plantId) => {
    if (!confirm('Are you sure you want to delete this plant?')) return;

    setLoading(true);
    try {
      const res = await fetch(`${API_BASE}/plants/${plantId}`, { method: 'DELETE' });
      const data = await res.json();
      if (res.ok) {
        addNotification('Plant deleted successfully');
        onRefresh();
      } else {
        addNotification(data.message, 'error');
      }
    } catch (err) {
      addNotification('Failed to delete plant', 'error');
    }
    setLoading(false);
  };

  return (
    <div className="space-y-6">
      <div className="bg-white/80 backdrop-blur-sm rounded-2xl shadow-lg p-6 border border-green-100">
        <h2 className="text-xl font-bold text-gray-800 mb-4 flex items-center gap-2">
          <Plus className="text-green-600" />
          Add New Plant
        </h2>
        
        <div className="grid grid-cols-2 gap-4 mb-4">
          <div>
            <label className="block text-sm font-medium text-gray-700 mb-2">Plant Type</label>
            <select
              value={formData.plantType}
              onChange={e => setFormData({ ...formData, plantType: e.target.value })}
              className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
            >
              <option value="flower">Flowering Plant</option>
              <option value="tree">Tree</option>
            </select>
          </div>

          <div>
            <label className="block text-sm font-medium text-gray-700 mb-2">Maintenance Level</label>
            <select
              value={formData.maintenance}
              onChange={e => setFormData({ ...formData, maintenance: e.target.value })}
              className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
            >
              <option value="low">Low Maintenance</option>
              <option value="high">High Maintenance</option>
            </select>
          </div>

          <div>
            <label className="block text-sm font-medium text-gray-700 mb-2">Price (R)</label>
            <input
              type="number"
              value={formData.price}
              onChange={e => setFormData({ ...formData, price: parseFloat(e.target.value) })}
              className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
            />
          </div>

          {formData.plantType === 'flower' ? (
            <div>
              <label className="block text-sm font-medium text-gray-700 mb-2">Color</label>
              <select
                value={formData.color}
                onChange={e => setFormData({ ...formData, color: e.target.value })}
                className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
              >
                <option>Red</option>
                <option>Pink</option>
                <option>White</option>
                <option>Yellow</option>
                <option>Purple</option>
              </select>
            </div>
          ) : (
            <div>
              <label className="block text-sm font-medium text-gray-700 mb-2">Height (m)</label>
              <input
                type="number"
                step="0.1"
                value={formData.height}
                onChange={e => setFormData({ ...formData, height: parseFloat(e.target.value) })}
                className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
              />
            </div>
          )}

          <div className="col-span-2">
            <label className="block text-sm font-medium text-gray-700 mb-2">Container</label>
            <select
              value={formData.container}
              onChange={e => setFormData({ ...formData, container: e.target.value })}
              className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
            >
              <option>Wood</option>
              <option>Cedar</option>
              <option>Plastic</option>
              <option>Large Wood</option>
            </select>
          </div>
        </div>

        <div className="flex gap-3">
          <button
            onClick={addPlant}
            className="flex-1 bg-gradient-to-r from-green-500 to-emerald-600 text-white px-6 py-3 rounded-lg font-medium hover:from-green-600 hover:to-emerald-700 transition-all shadow-md hover:shadow-lg"
          >
            Add Plant
          </button>
          <button
            onClick={growPlants}
            className="bg-gradient-to-r from-blue-500 to-indigo-600 text-white px-6 py-3 rounded-lg font-medium hover:from-blue-600 hover:to-indigo-700 transition-all shadow-md hover:shadow-lg"
          >
            Grow All to Maturity
          </button>
        </div>
      </div>

      <div className="bg-white/80 backdrop-blur-sm rounded-2xl shadow-lg p-6 border border-green-100">
        <h3 className="text-lg font-bold text-gray-800 mb-4">Current Plants Inventory</h3>

        {inventory.items && inventory.items.length > 0 ? (
          <div className="space-y-3">
            {inventory.items.map((plant, idx) => (
              <div key={idx} className="flex items-center justify-between p-4 bg-gradient-to-r from-green-50 to-emerald-50 rounded-lg border border-green-200">
                <div className="flex items-center gap-3">
                  <div className="w-3 h-3 bg-green-500 rounded-full"></div>
                  <div>
                    <div className="font-semibold text-gray-800">{plant.name}</div>
                    <div className="text-sm text-gray-500">
                      {plant.type} • {plant.container} • R{plant.price.toFixed(2)}
                      {plant.color && ` • ${plant.color}`}
                      {plant.height && ` • ${plant.height}m`}
                    </div>
                  </div>
                </div>
                <button
                  onClick={() => deletePlant(plant.id)}
                  className="bg-red-500 hover:bg-red-600 text-white p-2 rounded-lg transition-colors"
                  title="Delete plant"
                >
                  <Trash2 size={16} />
                </button>
              </div>
            ))}
          </div>
        ) : (
          <div className="text-center py-8">
            <Leaf className="mx-auto text-green-500 mb-3" size={48} />
            <p className="text-gray-500">No plants in inventory yet</p>
            <p className="text-sm text-gray-400 mt-1">Add some plants to get started!</p>
          </div>
        )}
      </div>

      <div className="bg-white/80 backdrop-blur-sm rounded-2xl shadow-lg p-6 border border-green-100">
        <h3 className="text-lg font-bold text-gray-800 mb-4">Garden Statistics</h3>
        <div className="grid grid-cols-3 gap-4">
          <div className="bg-gradient-to-br from-green-50 to-emerald-50 p-4 rounded-xl border border-green-200">
            <div className="text-3xl font-bold text-green-600">{plants.plant_count || 0}</div>
            <div className="text-sm text-gray-600 mt-1">Total Plants</div>
          </div>
          <div className="bg-gradient-to-br from-blue-50 to-indigo-50 p-4 rounded-xl border border-blue-200">
            <div className="text-3xl font-bold text-blue-600">{inventory.total_plants || 0}</div>
            <div className="text-sm text-gray-600 mt-1">In Inventory</div>
          </div>
          <div className="bg-gradient-to-br from-purple-50 to-pink-50 p-4 rounded-xl border border-purple-200">
            <div className="text-3xl font-bold text-purple-600">✓</div>
            <div className="text-sm text-gray-600 mt-1">All Mature</div>
          </div>
        </div>
      </div>
    </div>
  );
};

const CustomersTab = ({ customers, setCustomers, addNotification, setLoading }) => {
  const [name, setName] = useState('');
  const [customerId, setCustomerId] = useState('');

  const registerCustomer = async () => {
    if (!name.trim()) {
      addNotification('Please enter a name', 'error');
      return;
    }

    setLoading(true);
    try {
      const res = await fetch(`${API_BASE}/customers`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ 
          name: name.trim(), 
          id: customerId.trim() || name.trim().toLowerCase().replace(/\s+/g, '_') 
        })
      });

      const data = await res.json();
      if (res.ok) {
        setCustomers(prev => [...prev, { id: data.customer_id, name: data.name }]);
        addNotification(`Customer ${data.name} registered!`);
        setName('');
        setCustomerId('');
      } else {
        addNotification(data.message, 'error');
      }
    } catch (err) {
      addNotification('Failed to register customer', 'error');
    }
    setLoading(false);
  };

  return (
    <div className="space-y-6">
      <div className="bg-white/80 backdrop-blur-sm rounded-2xl shadow-lg p-6 border border-green-100">
        <h2 className="text-xl font-bold text-gray-800 mb-4 flex items-center gap-2">
          <Users className="text-green-600" />
          Register New Customer
        </h2>
        
        <div className="grid grid-cols-2 gap-4 mb-4">
          <div>
            <label className="block text-sm font-medium text-gray-700 mb-2">Customer Name</label>
            <input
              type="text"
              value={name}
              onChange={e => setName(e.target.value)}
              placeholder="John Doe"
              className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
            />
          </div>
          <div>
            <label className="block text-sm font-medium text-gray-700 mb-2">Customer ID (optional)</label>
            <input
              type="text"
              value={customerId}
              onChange={e => setCustomerId(e.target.value)}
              placeholder="Auto-generated if empty"
              className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent"
            />
          </div>
        </div>

        <button
          onClick={registerCustomer}
          className="w-full bg-gradient-to-r from-green-500 to-emerald-600 text-white px-6 py-3 rounded-lg font-medium hover:from-green-600 hover:to-emerald-700 transition-all shadow-md hover:shadow-lg"
        >
          Register Customer
        </button>
      </div>

      <div className="bg-white/80 backdrop-blur-sm rounded-2xl shadow-lg p-6 border border-green-100">
        <h3 className="text-lg font-bold text-gray-800 mb-4">Registered Customers</h3>
        {customers.length === 0 ? (
          <p className="text-gray-500 text-center py-8">No customers registered yet</p>
        ) : (
          <div className="space-y-2">
            {customers.map((customer, idx) => (
              <div key={idx} className="flex items-center justify-between p-4 bg-gradient-to-r from-green-50 to-emerald-50 rounded-lg border border-green-200">
                <div>
                  <div className="font-semibold text-gray-800">{customer.name}</div>
                  <div className="text-sm text-gray-500">ID: {customer.id}</div>
                </div>
                <div className="bg-green-500 text-white px-3 py-1 rounded-full text-sm font-medium">
                  Active
                </div>
              </div>
            ))}
          </div>
        )}
      </div>
    </div>
  );
};

const OrdersTab = ({ customers, orders, setOrders, addNotification, setLoading }) => {
  const [selectedCustomer, setSelectedCustomer] = useState('');
  const [currentOrder, setCurrentOrder] = useState(null);
  const [plantName, setPlantName] = useState('Rose');
  const [decorate, setDecorate] = useState(false);
  const [paymentType, setPaymentType] = useState('cash');
  const [paymentDetails, setPaymentDetails] = useState({});

  const createOrder = async () => {
    if (!selectedCustomer) {
      addNotification('Please select a customer', 'error');
      return;
    }

    setLoading(true);
    try {
      const res = await fetch(`${API_BASE}/orders`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ customer_id: selectedCustomer })
      });

      const data = await res.json();
      if (res.ok) {
        setCurrentOrder({ id: data.order_id, items: [], total: 0 });
        addNotification('Order created!');
      } else {
        addNotification(data.message, 'error');
      }
    } catch (err) {
      addNotification('Failed to create order', 'error');
    }
    setLoading(false);
  };

  const addItem = async () => {
    if (!currentOrder) return;

    setLoading(true);
    try {
      const res = await fetch(`${API_BASE}/orders/${currentOrder.id}/items`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ plant_name: plantName, decorate })
      });

      const data = await res.json();
      if (res.ok) {
        setCurrentOrder(prev => ({
          ...prev,
          items: [...prev.items, { plant: data.plant, price: data.price }],
          total: prev.total + data.price
        }));
        addNotification(`Added ${data.plant} to order`);
      } else {
        addNotification(data.message, 'error');
      }
    } catch (err) {
      addNotification('Failed to add item', 'error');
    }
    setLoading(false);
  };

  const checkout = async () => {
    if (!currentOrder) return;

    setLoading(true);
    try {
      const body = { payment_type: paymentType, ...paymentDetails };
      
      const res = await fetch(`${API_BASE}/orders/${currentOrder.id}/checkout`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(body)
      });

      const data = await res.json();
      if (res.ok) {
        addNotification(`Order completed! Total: R${data.total}`);
        setCurrentOrder(null);
        setPaymentDetails({});
      } else {
        addNotification(data.message, 'error');
      }
    } catch (err) {
      addNotification('Checkout failed', 'error');
    }
    setLoading(false);
  };

  return (
    <div className="space-y-6">
      <div className="grid grid-cols-2 gap-6">
        <div className="bg-white/80 backdrop-blur-sm rounded-2xl shadow-lg p-6 border border-green-100">
          <h2 className="text-xl font-bold text-gray-800 mb-4 flex items-center gap-2">
            <ShoppingCart className="text-green-600" />
            New Order
          </h2>

          <div className="space-y-4">
            <div>
              <label className="block text-sm font-medium text-gray-700 mb-2">Select Customer</label>
              <select
                value={selectedCustomer}
                onChange={e => setSelectedCustomer(e.target.value)}
                className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500"
              >
                <option value="">Choose customer...</option>
                {customers.map((c, idx) => (
                  <option key={idx} value={c.id}>{c.name}</option>
                ))}
              </select>
            </div>

            <button
              onClick={createOrder}
              disabled={!selectedCustomer || currentOrder}
              className="w-full bg-gradient-to-r from-green-500 to-emerald-600 text-white px-6 py-3 rounded-lg font-medium hover:from-green-600 hover:to-emerald-700 disabled:opacity-50 disabled:cursor-not-allowed transition-all"
            >
              Create Order
            </button>

            {currentOrder && (
              <>
                <div className="border-t pt-4">
                  <label className="block text-sm font-medium text-gray-700 mb-2">Plant Name</label>
                  <input
                    type="text"
                    value={plantName}
                    onChange={e => setPlantName(e.target.value)}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 mb-3"
                  />

                  <label className="flex items-center gap-2 mb-3">
                    <input
                      type="checkbox"
                      checked={decorate}
                      onChange={e => setDecorate(e.target.checked)}
                      className="w-4 h-4 text-green-600 rounded focus:ring-green-500"
                    />
                    <span className="text-sm font-medium text-gray-700">Gift wrap & bow</span>
                  </label>

                  <button
                    onClick={addItem}
                    className="w-full bg-blue-500 text-white px-6 py-2 rounded-lg font-medium hover:bg-blue-600 transition-all"
                  >
                    Add Item
                  </button>
                </div>

                <div className="border-t pt-4">
                  <label className="block text-sm font-medium text-gray-700 mb-2">Payment Method</label>
                  <select
                    value={paymentType}
                    onChange={e => setPaymentType(e.target.value)}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 mb-3"
                  >
                    <option value="cash">Cash</option>
                    <option value="card">Credit Card</option>
                    <option value="mobile">Mobile Payment</option>
                  </select>

                  {paymentType === 'cash' && (
                    <input
                      type="number"
                      placeholder="Amount tendered"
                      onChange={e => setPaymentDetails({ amount_tendered: parseFloat(e.target.value) })}
                      className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 mb-3"
                    />
                  )}

                  {paymentType === 'card' && (
                    <>
                      <input
                        type="text"
                        placeholder="Card number"
                        onChange={e => setPaymentDetails(prev => ({ ...prev, card_number: e.target.value }))}
                        className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 mb-2"
                      />
                      <input
                        type="text"
                        placeholder="Expiry (MM/YY)"
                        onChange={e => setPaymentDetails(prev => ({ ...prev, expiry: e.target.value }))}
                        className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 mb-3"
                      />
                    </>
                  )}

                  {paymentType === 'mobile' && (
                    <>
                      <input
                        type="text"
                        placeholder="Phone number"
                        onChange={e => setPaymentDetails(prev => ({ ...prev, phone: e.target.value }))}
                        className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 mb-2"
                      />
                      <input
                        type="text"
                        placeholder="Provider"
                        onChange={e => setPaymentDetails(prev => ({ ...prev, provider: e.target.value }))}
                        className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-green-500 mb-3"
                      />
                    </>
                  )}

                  <button
                    onClick={checkout}
                    className="w-full bg-gradient-to-r from-purple-500 to-pink-600 text-white px-6 py-3 rounded-lg font-medium hover:from-purple-600 hover:to-pink-700 transition-all shadow-md hover:shadow-lg"
                  >
                    <div className="flex items-center justify-center gap-2">
                      <DollarSign size={18} />
                      Checkout
                    </div>
                  </button>
                </div>
              </>
            )}
          </div>
        </div>

        <div className="bg-white/80 backdrop-blur-sm rounded-2xl shadow-lg p-6 border border-green-100">
          <h3 className="text-lg font-bold text-gray-800 mb-4">Current Order</h3>
          
          {!currentOrder ? (
            <p className="text-gray-500 text-center py-8">No active order</p>
          ) : (
            <div>
              <div className="space-y-2 mb-4">
                {currentOrder.items.map((item, idx) => (
                  <div key={idx} className="flex justify-between items-center p-3 bg-green-50 rounded-lg">
                    <span className="font-medium text-gray-700">{item.plant}</span>
                    <span className="text-green-600 font-semibold">R{item.price.toFixed(2)}</span>
                  </div>
                ))}
              </div>
              
              <div className="border-t pt-4">
                <div className="flex justify-between items-center text-xl font-bold">
                  <span>Total:</span>
                  <span className="text-green-600">R{currentOrder.total.toFixed(2)}</span>
                </div>
              </div>
            </div>
          )}
        </div>
      </div>
    </div>
  );
};

const DemoTab = ({ onRefresh, addNotification, setLoading }) => {
  const runDemo = async () => {
    setLoading(true);
    try {
      const res = await fetch(`${API_BASE}/demo/quick`, { method: 'POST' });
      const data = await res.json();

      if (res.ok) {
        addNotification(`Demo complete! Added ${data.plants_added} plants`);
        onRefresh();
      }
    } catch (err) {
      addNotification('Demo failed', 'error');
    }
    setLoading(false);
  };

  return (
    <div className="space-y-6">
      <div className="bg-white/80 backdrop-blur-sm rounded-2xl shadow-lg p-6 border border-green-100">
        <h2 className="text-xl font-bold text-gray-800 mb-4 flex items-center gap-2">
          <Package className="text-green-600" />
          Quick Demo Setup
        </h2>

        <p className="text-gray-600 mb-6">
          This will add some sample plants and customers to demonstrate the nursery management system.
        </p>

        <button
          onClick={runDemo}
          className="w-full bg-gradient-to-r from-green-500 to-emerald-600 text-white px-6 py-3 rounded-lg font-medium hover:from-green-600 hover:to-emerald-700 transition-all shadow-md hover:shadow-lg"
        >
          Run Demo
        </button>
      </div>
    </div>
  );
};

export default App;
