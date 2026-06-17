<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>HShop — Modern Ecommerce</title>
  <link rel="preconnect" href="https://fonts.googleapis.com"/>
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin/>
  <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;500;600;700&display=swap" rel="stylesheet"/>
  <link rel="stylesheet" href="styles.css"/>
</head>
<body>

  <!-- TOP BAR -->
  <div class="topbar">
    <span>Free shipping on orders over $50 &nbsp;·&nbsp; Use code <strong>HSHOP10</strong> for 10% off</span>
  </div>

  <!-- HEADER -->
  <header class="header">
    <div class="header-inner">

      <!-- Logo -->
      <a href="#" class="logo">B<span>Shop</span></a>

      <!-- Search Bar -->
      <div class="search-wrapper" id="searchWrapper">
        <div class="search-bar">
          <svg class="search-icon" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
            <circle cx="11" cy="11" r="8"/><line x1="21" y1="21" x2="16.65" y2="16.65"/>
          </svg>
          <input
            type="text"
            id="searchInput"
            class="search-input"
            placeholder="Search for products, brands and more…"
            autocomplete="off"
          />
          <button class="search-btn">Search</button>
        </div>

        <!-- Dropdown -->
        <div class="search-dropdown" id="searchDropdown">
          <div class="dropdown-label">Suggested Products</div>

         
          <div class="dropdown-footer">
            <span>Press Enter to see all results</span>
          </div>
        </div>
      </div>

      <!-- Header Actions -->
      <div class="header-actions">
        <a href="#" class="action-btn" title="Account">
          <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
            <path d="M20 21v-2a4 4 0 0 0-4-4H8a4 4 0 0 0-4 4v2"/><circle cx="12" cy="7" r="4"/>
          </svg>
          <span>Account</span>
        </a>
        <a href="#" class="action-btn" title="Wishlist">
          <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
            <path d="M20.84 4.61a5.5 5.5 0 0 0-7.78 0L12 5.67l-1.06-1.06a5.5 5.5 0 0 0-7.78 7.78l1.06 1.06L12 21.23l7.78-7.78 1.06-1.06a5.5 5.5 0 0 0 0-7.78z"/>
          </svg>
          <span>Wishlist</span>
        </a>
        <a href="#" class="action-btn cart-btn" title="Cart">
          <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
            <circle cx="9" cy="21" r="1"/><circle cx="20" cy="21" r="1"/>
            <path d="M1 1h4l2.68 13.39a2 2 0 0 0 2 1.61h9.72a2 2 0 0 0 2-1.61L23 6H6"/>
          </svg>
          <span>Cart</span>
          <span class="cart-badge">3</span>
        </a>
      </div>

    </div>

    <!-- NAV -->
    <nav class="nav">
      <div class="nav-inner">
        <a href="#" class="nav-link active">Home</a>
        <a href="#" class="nav-link">New Arrivals</a>
        <a href="#" class="nav-link">Men</a>
        <a href="#" class="nav-link">Women</a>
        <a href="#" class="nav-link">Electronics</a>
        <a href="#" class="nav-link">Beauty</a>
        <a href="#" class="nav-link">Sports</a>
        <a href="#" class="nav-link sale">Sale <span class="sale-badge">Up to 50%</span></a>
      </div>
    </nav>
  </header>

  <!-- HERO -->
  <section class="hero">
    <div class="hero-content">
      <span class="hero-tag">New Collection 2025</span>
      <h1 class="hero-title">Style That<br/><em>Speaks</em> for You</h1>
      <p class="hero-sub">Curated fashion, tech, and lifestyle picks — delivered to your door.</p>
      <div class="hero-actions">
        <a href="#" class="btn-primary">Shop Now</a>
        <a href="#" class="btn-ghost">View Lookbook</a>
      </div>
    </div>
    <div class="hero-image">
      <img src="https://images.unsplash.com/photo-1483985988355-763728e1935b?w=700&q=80" alt="Fashion model"/>
      <div class="hero-badge">
        <span class="badge-num">2K+</span>
        <span class="badge-text">Products</span>
      </div>
    </div>
  </section>

  <!-- CATEGORIES -->
  <section class="section categories-section">
    <div class="container">
      <h2 class="section-title">Shop by Category</h2>
      <div class="categories-grid">
        <a href="#" class="category-card">
          <img src="https://images.unsplash.com/photo-1441986300917-64674bd600d8?w=400&q=80" alt="Men"/>
          <div class="category-overlay"><span>Men</span></div>
        </a>
        <a href="#" class="category-card">
          <img src="https://images.unsplash.com/photo-1567401893414-76b7b1e5a7a5?w=400&q=80" alt="Women"/>
          <div class="category-overlay"><span>Women</span></div>
        </a>
        <a href="#" class="category-card">
          <img src="https://images.unsplash.com/photo-1468495244123-6c6c332eeece?w=400&q=80" alt="Electronics"/>
          <div class="category-overlay"><span>Electronics</span></div>
        </a>
        <a href="#" class="category-card">
          <img src="https://images.unsplash.com/photo-1526170375885-4d8ecf77b99f?w=400&q=80" alt="Beauty"/>
          <div class="category-overlay"><span>Beauty</span></div>
        </a>
      </div>
    </div>
  </section>

  <!-- FEATURED PRODUCTS -->
  <section class="section products-section">
    <div class="container">
      <div class="section-head">
        <h2 class="section-title">Featured Products</h2>
        <a href="#" class="view-all">View All →</a>
      </div>
      <div class="products-grid">

        <div class="product-card">
          <div class="product-card-img">
            <img src="https://images.unsplash.com/photo-1523275335684-37898b6baf30?w=400&q=80" alt="Watch"/>
            <div class="product-card-actions">
              <button title="Wishlist">♡</button>
              <button title="Quick View">⊕</button>
            </div>
          </div>
          <div class="product-card-body">
            <span class="product-card-cat">Accessories</span>
            <h3 class="product-card-name">Minimalist Steel Watch</h3>
            <div class="product-card-footer">
              <span class="product-card-price">$129.00</span>
              <button class="add-cart-btn">Add to Cart</button>
            </div>
          </div>
        </div>

        <div class="product-card">
          <div class="product-card-img">
            <img src="https://images.unsplash.com/photo-1491553895911-0055eca6402d?w=400&q=80" alt="Sneakers"/>
            <span class="product-badge">New</span>
            <div class="product-card-actions">
              <button title="Wishlist">♡</button>
              <button title="Quick View">⊕</button>
            </div>
          </div>
          <div class="product-card-body">
            <span class="product-card-cat">Footwear</span>
            <h3 class="product-card-name">Urban Runner Sneakers</h3>
            <div class="product-card-footer">
              <span class="product-card-price">$210.00</span>
              <button class="add-cart-btn">Add to Cart</button>
            </div>
          </div>
        </div>

        <div class="product-card">
          <div class="product-card-img">
            <img src="https://images.unsplash.com/photo-1505740420928-5e560c06d30e?w=400&q=80" alt="Headphones"/>
            <span class="product-badge sale-tag">−20%</span>
            <div class="product-card-actions">
              <button title="Wishlist">♡</button>
              <button title="Quick View">⊕</button>
            </div>
          </div>
          <div class="product-card-body">
            <span class="product-card-cat">Electronics</span>
            <h3 class="product-card-name">Studio Pro Headphones</h3>
            <div class="product-card-footer">
              <span class="product-card-price">$349.00 <s>$435.00</s></span>
              <button class="add-cart-btn">Add to Cart</button>
            </div>
          </div>
        </div>

        <div class="product-card">
          <div class="product-card-img">
            <img src="https://images.unsplash.com/photo-1548036328-c9fa89d128fa?w=400&q=80" alt="Bag"/>
            <div class="product-card-actions">
              <button title="Wishlist">♡</button>
              <button title="Quick View">⊕</button>
            </div>
          </div>
          <div class="product-card-body">
            <span class="product-card-cat">Bags</span>
            <h3 class="product-card-name">Leather Tote Bag</h3>
            <div class="product-card-footer">
              <span class="product-card-price">$175.00</span>
              <button class="add-cart-btn">Add to Cart</button>
            </div>
          </div>
        </div>

      </div>
    </div>
  </section>

  <!-- BANNER -->
  <section class="promo-banner">
    <div class="promo-content">
      <span class="promo-tag">Limited Time</span>
      <h2>Summer Sale — Up to 50% Off</h2>
      <p>Don't miss our biggest sale of the year. Ends July 31st.</p>
      <a href="#" class="btn-primary">Shop the Sale</a>
    </div>
  </section>

  <!-- FOOTER -->
  <footer class="footer">
    <div class="container footer-inner">
      <div class="footer-brand">
        <a href="#" class="logo">H<span>Shop</span></a>
        <p>Your destination for curated fashion, tech, and lifestyle products.</p>
        <div class="social-links">
          <a href="#">Instagram</a>
          <a href="#">Twitter</a>
          <a href="#">Facebook</a>
        </div>
      </div>
      <div class="footer-links">
        <h4>Company</h4>
        <a href="#">About Us</a>
        <a href="#">Careers</a>
        <a href="#">Press</a>
        <a href="#">Blog</a>
      </div>
      <div class="footer-links">
        <h4>Support</h4>
        <a href="#">Help Center</a>
        <a href="#">Track Order</a>
        <a href="#">Returns</a>
        <a href="#">Contact Us</a>
      </div>
      <div class="footer-links">
        <h4>Legal</h4>
        <a href="#">Privacy Policy</a>
        <a href="#">Terms of Service</a>
        <a href="#">Cookie Settings</a>
      </div>
    </div>
    <div class="footer-bottom">
      <p>© 2025 HShop. All rights reserved.</p>
    </div>
  </footer>

  <script>
    // ── Search dropdown demo logic ──
    // Replace this section with your own implementation.
    const input = document.getElementById('searchInput');
    const dropdown = document.getElementById('searchDropdown');

    input.addEventListener('focus', () => {
      if (input.value.trim() !== '' || true) { // show on focus for demo
        dropdown.classList.add('open');
      }
    });

    input.addEventListener("input", function(event) {
      // TODO: Replace with your real search/filter logic.
      // Show dropdown when there is input.
     let searchText =  input.value;
    document.getElementById("searchDropdown").innerHTML = "<p style=\"display:flex;justify-content:center;align-items:center;gap:8px;padding:12px 0;\"><span aria-hidden=\"true\">&#9203;</span><span>Loading...</span></p>";
     document.getElementById("searchDropdown").style.display = "block";


     //AJAX request

     const xhr = new XMLHttpRequest();
      xhr.open("GET", "search.php?q=" + searchText, true);
      xhr.send();


      xhr.onreadystatechange = function() {

        if (this.readyState == 4 && this.status == 200) {
          const res = JSON.parse(this.responseText);
          let allItemsHTML = " ";
          res.forEach(function(item){
            const itemHTML = `
             <div class="dropdown-item">
            <div class="product-img-wrap">
              <img src="${item.image_url}" alt="${item.name}"/>
            </div>
            <div class="product-info">
              <span class="product-name">${item.name}</span>
              <span class="product-category">${item.category}</span>
            </div>
            <span class="product-price">${item.price}</span>
          </div>
            `;
            allItemsHTML += itemHTML;
          });
          document.getElementById("searchDropdown").innerHTML = allItemsHTML;
        }
      }
    });

    document.addEventListener('click', (e) => {
      if (!document.getElementById('searchWrapper').contains(e.target)) {
        dropdown.classList.remove('open');
      }
    });
  </script>

</body>
</html>
