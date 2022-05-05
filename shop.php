<?php 
session_start();
include ('../Controller/login.php');
$user_data = check_login();
include('../controller/panierC.php');
$article = new panierC ;
$article->add($user_data['idUtilisateur']);
?>

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<meta name="description" content="Find easily a doctor and book online an appointment">
	<meta name="author" content="Ansonika">
	<title>FINDOCTOR - Find easily a doctor and book online an appointment</title>

	<!-- Favicons-->
	<link rel="shortcut icon" href="img/favicon.ico" type="image/x-icon">
	<link rel="apple-touch-icon" type="image/x-icon" href="img/apple-touch-icon-57x57-precomposed.png">
	<link rel="apple-touch-icon" type="image/x-icon" sizes="72x72" href="img/apple-touch-icon-72x72-precomposed.png">
	<link rel="apple-touch-icon" type="image/x-icon" sizes="114x114" href="img/apple-touch-icon-114x114-precomposed.png">
	<link rel="apple-touch-icon" type="image/x-icon" sizes="144x144" href="img/apple-touch-icon-144x144-precomposed.png">

	<!-- GOOGLE WEB FONT -->
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;500;600;700;800&display=swap" rel="stylesheet">

	<!-- BASE CSS -->
	<link href="css/bootstrap.min.css" rel="stylesheet">
	<link href="css/style.css" rel="stylesheet">
	<link href="css/menu.css" rel="stylesheet">
	<link href="css/vendors.css" rel="stylesheet">
	<link href="css/icon_fonts/css/all_icons_min.css" rel="stylesheet">
   
    <!-- SPECIFIC CSS -->
    <link href="css/date_picker.css" rel="stylesheet">
    
	<!-- YOUR CUSTOM CSS -->
	<link href="css/custom.css" rel="stylesheet">

</head>

<body>

	<div id="preloader" class="Fixed">
		<div data-loader="circle-side"></div>
	</div>
	<!-- /Preload-->
	
	<div id="page">		
	<header class="static">	
		<a href="#menu" class="btn_mobile">
			<div class="hamburger hamburger--spin" id="hamburger">
				<div class="hamburger-box">
					<div class="hamburger-inner"></div>
				</div>
			</div>
		</a>
		<!-- /btn_mobile-->
		<div class="container">
			<div class="row">
				<div class="col-lg-3 col-6">
					<div id="logo">
						<a href="index.html" title="Findoctor"><img src="img/logo.png" alt="" width="163" height="36"></a>
					</div>
				</div>
				<div class="col-lg-9 col-6">
					<ul id="top_access">
						<li><a href="login.html"><i class="pe-7s-user"></i></a></li>
						<li><a href="register-doctor.html"><i class="pe-7s-add-user"></i></a></li>
					</ul>
					<nav id="menu" class="main-menu">
						<ul>
							<li>
								<span><a href="#0">Home</a></span>
								<ul>
									<li><a href="index.html">Home Default</a></li>
									<li><a href="index-2.html">Home Version 2</a></li>
									<li><a href="index-3.html">Home Version 3</a></li>
									<li><a href="index-4.html">Home Version 4</a></li>
									<li><a href="index-7.html">Home with Map</a></li>
                                    <li><a href="index-6.html">Revolution Slider</a></li>
									<li><a href="index-5.html">With Cookie Bar (EU law)</a></li>
								</ul>
							</li>
							<li>
								<span><a href="#0">Pages</a></span>
								<ul>
									<li>
										<span><a href="#0">List pages</a></span>
										<ul>
											<li><a href="list.html">List page</a></li>
											<li><a href="grid-list.html">List grid page</a></li>
											<li><a href="list-map.html">List map page</a></li>
										</ul>
									</li>
									<li>
										<span><a href="#0">Detail pages</a></span>
										<ul>
											<li><a href="detail-page.html">Detail page</a></li>
											<li><a href="detail-page-2.html">Detail page 2</a></li>
                                    		<li><a href="detail-page-3.html">Detail page 3</a></li>
											<li><a href="detail-page-working-booking.html">Detail working booking</a></li>
										</ul>
									</li>
									<li><a href="submit-review.html">Submit Review</a></li>
									<li><a href="blog-1.html">Blog</a></li>
									<li><a href="badges.html">Badges</a></li>
									<li><a href="login.html">Login</a></li>
									<li><a href="login-2.html">Login 2</a></li>
									<li><a href="register-doctor.html">Register Doctor</a></li>
									<li><a href="register-doctor-working.html">Working doctor register</a></li>
									<li><a href="register.html">Register</a></li>
									<li><a href="about.html">About Us</a></li>
									<li><a href="contacts.html">Contacts</a></li>
								</ul>
							</li>
							<li>
								<span><a href="#0">Extra Elements</a></span>
								<ul>
                                	<li><a href="detail-page-working-booking.html">Detail working booking</a></li>
                                    <li><a href="booking-page.html">Booking page</a></li>
                                    <li><a href="confirm.html">Confirm page</a></li>
                                	<li><a href="faq.html">Faq page</a></li>
                                    <li><a href="coming_soon/index.html">Coming soon</a></li>
                                    <li>
										<span><a href="#0">Pricing tables</a></span>
										<ul>
											<li><a href="pricing-tables-3.html">Pricing tables 1</a></li>
                                    		<li><a href="pricing-tables.html">Pricing tables 2</a></li>
                                    		<li><a href="pricing-tables-2.html">Pricing tables 3</a></li>
										</ul>
									</li>
									<li><a href="icon-pack-1.html">Icon pack 1</a></li>
									<li><a href="icon-pack-2.html">Icon pack 2</a></li>
									<li><a href="icon-pack-3.html">Icon pack 3</a></li>
									<li><a href="404.html">404 page</a></li>
								</ul>
							</li>
                            <li><span><a href="menu_2/index.html">Menu V2</a></span></li>
							<li><span><a href="admin_section/index.html" target="_blank">Admin</a></span></li>
							<li><span><a href="https://1.envato.market/1kDnR" target="_parent">Buy this template</a></span></li>
						</ul>
					</nav>
					<!-- /main-menu -->
				</div>
			</div>
		</div>
		<!-- /container -->
	</header>
	<!-- /header -->
	
   <main>
   <div id="results">
       <div class="container">
           <div class="row">
               <div class="col-md-6">
                   <h4><strong>Showing 10</strong> of 140 results</h4>
               </div>
               <div class="col-md-6">
                    <div class="search_bar_list">
                    <input type="text" class="form-control" placeholder="Ex. Specialist, Name, Doctor...">
                    <input type="submit" value="Search">
                </div>
               </div>
           </div>
           <!-- /row -->
       </div>
       <!-- /container -->
   </div>
   <!-- /results -->
   
   <div class="filters_listing">
		<div class="container">
			<ul class="clearfix">
				<li>
					<h6>Type</h6>
					<div class="switch-field">
						<input type="radio" id="all" name="type_patient" value="all" checked>
						<label for="all">All</label>
						<input type="radio" id="doctors" name="type_patient" value="doctors">
						<label for="doctors">Doctors</label>
						<input type="radio" id="clinics" name="type_patient" value="clinics">
						<label for="clinics">Clinics</label>
					</div>
				</li>
				<li>
					<h6>Layout</h6>
					<div class="layout_view">
						<a href="#0" class="active"><i class="icon-th"></i></a>
						<a href="list.html"><i class="icon-th-list"></i></a>
						<a href="list-map.html"><i class="icon-map-1"></i></a>
					</div>
				</li>
				<li>
					<h6>Sort by</h6>
					<select name="orderby" class="selectbox">
					<option value="Closest">Closest</option>
					<option value="Best rated">Best rated</option>
					<option value="Men">Men</option>
					<option value="Women">Women</option>
					</select>
				</li>
			</ul>
		</div>
		<!-- /container -->
	</div>
	<!-- /filters -->
	   
	<div class="container margin_60_35">
		<div class="row">
			<div class="col-lg-8">
				<div class="row">
					<div class="col-md-6">
						<div class="box_list wow fadeIn">
							<a href="#0" class="wish_bt"></a>
							<figure>
								<a href="detail-page.html"><img src="img/doctor_listing_5.jpg" class="img-fluid" alt="">
									<div class="preview"><span>Read more</span></div>
								</a>
							</figure>
							<div class="wrapper">
								<small>50 $</small>
								<h3>Product 1</h3>
								<p>Id placerat tacimates definitionem sea, prima quidam vim no. Duo nobis persecuti cuodo....</p>
								<span class="rating"><i class="icon_star voted"></i><i class="icon_star voted"></i><i class="icon_star voted"></i><i class="icon_star"></i><i class="icon_star"></i> <small>(145)</small></span>
								<form action="shop.php?add" id="ajouterpanier1" method="post">
									<input type="number" min=1 name="qte" placeholder="select quantity">
									<input type="text" name="nomprod" value="product 1" hidden>
									<input type="number" name="prix" value="50" hidden>
								</form>
							</div>
							<ul>
								<li><a href="#" onclick="submit1()">Buy now</a></li>
								<script>
									function submit1() {
								   document.getElementById("ajouterpanier1").submit();
								   }
							   </script>
							</ul>
						</div>
					</div>
					<!-- /box_list -->

					<div class="col-md-6">
						<div class="box_list wow fadeIn">
							<a href="#0" class="wish_bt"></a>
							<figure>
								<a href="detail-page.html"><img src="img/doctor_listing_6.jpg" class="img-fluid" alt="">
									<div class="preview"><span>See more</span></div>
								</a>
							</figure>
							<div class="wrapper">
								<small>20 $</small>
								<h3>Product 2</h3>
								<p>Id placerat tacimates definitionem sea, prima quidam vim no. Duo nobis persecuti cuodo....</p>
								<span class="rating"><i class="icon_star voted"></i><i class="icon_star voted"></i><i class="icon_star voted"></i><i class="icon_star"></i><i class="icon_star"></i> <small>(145)</small></span>
								<form action="shop.php?add" id="ajouterpanier2" method="post">
								<input type="number" min=1 name="qte" placeholder="select quantity">
								<input type="text" name="nomprod" value="piece" hidden>
								<input type="number" name="prix" value="20" hidden>
								</form>
							</div>
							<ul>
								<li><a href="#" onclick="submit2()">Buy now</a></li>
								<script>
									function submit2() {
								   document.getElementById("ajouterpanier2").submit();
								   }
							   </script>
							</ul>
						</div>
					</div>
					<!-- /box_list -->

				</div>
				<!-- /row -->

				<nav aria-label="" class="add_top_20">
					<ul class="pagination pagination-sm">
						<li class="page-item disabled">
							<a class="page-link" href="#" tabindex="-1">Previous</a>
						</li>
						<li class="page-item active"><a class="page-link" href="#">1</a></li>
						<li class="page-item"><a class="page-link" href="#">2</a></li>
						<li class="page-item"><a class="page-link" href="#">3</a></li>
						<li class="page-item">
							<a class="page-link" href="#">Next</a>
						</li>
					</ul>
				</nav>
				<!-- /pagination -->
			</div>
			<!-- /col -->
			
			<aside class="col-lg-4" id="sidebar">
				<div id="map_listing" class="normal_list">
				</div>
			</aside>
			<!-- /aside -->
			
		</div>
		<!-- /row -->
	</div>
	<!-- /container -->
	</main>
	<!-- /main -->
	
	<footer>
		<div class="container margin_60_35">
			<div class="row">
				<div class="col-lg-3 col-md-12">
					<p>
						<a href="index.html" title="Findoctor">
							<img src="img/logo.png" data-retina="true" alt="" width="163" height="36" class="img-fluid">
						</a>
					</p>
				</div>
				<div class="col-lg-3 col-md-4">
					<h5>About</h5>
					<ul class="links">
						<li><a href="#0">About us</a></li>
						<li><a href="blog.html">Blog</a></li>
						<li><a href="#0">FAQ</a></li>
						<li><a href="login.html">Login</a></li>
						<li><a href="register.html">Register</a></li>
					</ul>
				</div>
				<div class="col-lg-3 col-md-4">
					<h5>Useful links</h5>
					<ul class="links">
						<li><a href="#0">Doctors</a></li>
						<li><a href="#0">Clinics</a></li>
						<li><a href="#0">Specialization</a></li>
						<li><a href="#0">Join as a Doctor</a></li>
						<li><a href="#0">Download App</a></li>
					</ul>
				</div>
				<div class="col-lg-3 col-md-4">
					<h5>Contact with Us</h5>
					<ul class="contacts">
						<li><a href="tel://61280932400"><i class="icon_mobile"></i> + 61 23 8093 3400</a></li>
						<li><a href="mailto:info@findoctor.com"><i class="icon_mail_alt"></i> help@findoctor.com</a></li>
					</ul>
					<div class="follow_us">
						<h5>Follow us</h5>
						<ul>
							<li><a href="#0"><i class="social_facebook"></i></a></li>
							<li><a href="#0"><i class="social_twitter"></i></a></li>
							<li><a href="#0"><i class="social_linkedin"></i></a></li>
							<li><a href="#0"><i class="social_instagram"></i></a></li>
						</ul>
					</div>
				</div>
			</div>
			<!--/row-->
			<hr>
			<div class="row">
				<div class="col-md-8">
					<ul id="additional_links">
						<li><a href="#0">Terms and conditions</a></li>
						<li><a href="#0">Privacy</a></li>
					</ul>
				</div>
				<div class="col-md-4">
					<div id="copy">© Findoctor</div>
				</div>
			</div>
		</div>
	</footer>
	<!--/footer-->
	</div>
	<!-- page -->

	<div id="toTop"></div>
	<!-- Back to top button -->

	<!-- COMMON SCRIPTS -->
	<script src="js/jquery-3.6.0.min.js"></script>
	<script src="js/common_scripts.min.js"></script>
	<script src="js/functions.js"></script>
	
	<!-- SPECIFIC SCRIPTS -->
	<script src="http://maps.googleapis.com/maps/api/js?key=AIzaSyCoz993id_Qq7AcfaoVzviC6swgvQRixuQ"></script>
	<script src="js/markerclusterer.js"></script>
    <script src="js/map_listing.js"></script>
    <script src="js/infobox.js"></script>


</body>
</html>