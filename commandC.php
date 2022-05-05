<?php 
    include_once 'config.php';

    class commandC{

        public function add()
        {
            if(isset($_GET['checkout'])){
            $con=config::getConnexion();
            if($_SERVER['REQUEST_METHOD'] == "POST")
            {
                //something was posted
                $element    = trim($_POST['element']);
                $nom    = trim($_POST['nom']);
                $adresse = trim($_POST['adresse']);
                $phone     = (int) $_POST['phone'];
                $prix   = (float) $_POST['prix'];
                if(!empty($element) && !empty($phone) && !empty($prix))
                {
                    //save to database
                    $sql = "INSERT INTO `command`( `prix`, `adresse`, `elements`, `nom`, `num_tel`) VALUES ('$prix','$adresse','$element','$nom','$phone')";
                    $sql2 = "TRUNCATE TABLE panier";
                    try {
                        $query=$con->prepare($sql);
                        $query->execute();
                        $query2=$con->prepare($sql2);
                        $query2->execute();
                        echo "<script type='text/javascript'>alert('merci pour votre achat');</script>";
                    } catch (Exception $e) {
                        echo "Error " . $e->getMessage();
                        exit();
                    }
                    die;
                }
            }
        }
        }

        public function read()
        {
            try {
                $con=config::getConnexion();
                // Create sql statment
                $sql = " select * from command";
                $resultp = $con->query($sql);
                return $resultp;
            } catch (Exception $e) {
                echo "Error " . $e->getMessage();
                exit();
            }
        }

        public function delete()
        {
            if(isset($_GET['delete'])){
                $con=config::getConnexion();
                if(isset($_GET['delete'])){
                    $id = $_GET['delete'];
                    $sql ="DELETE FROM `command` WHERE `id` = '$id' ";
                    try {
                        $query=$con->prepare($sql);
                        $query->execute();
                        header("Location:command.php");
                    } catch (Exception $e) {
                        echo "Error " . $e->getMessage();
                        exit();
                    }
            }}
        }

        public function gets ()
        {
            if(isset($_GET['id'])){
                $con=config::getConnexion();
                $id = $_GET['id'];
                $sql="SELECT * FROM `command` WHERE `id` =$id";
                try{  
                    $query=$con->prepare($sql);
                    $query->execute();
                }catch (Exception $e){
                    die('Erreur: '.$e->getMessage());
                }
                // Get the meeting
                $m = $query->fetch();
                return $m;
            }
        }

        public function update()
        {
            if(isset($_GET['update'])){
                $con=config::getConnexion();
                if($_SERVER['REQUEST_METHOD'] == "POST")
                {
                    //something was posted
                    $id=(int) $_POST['id'];
                    $nom    = trim($_POST['nom']);
                    $elements    = trim($_POST['elements']);
                    $adresse = trim($_POST['adresse']);
                    $num_tel     = (int) $_POST['num_tel'];
                    $prix   = (float) $_POST['prix'];
                    if(!empty($nom) && !empty($num_tel) && !empty($prix))
                    {
                        header("Location:command.php");
                        //save to database
                        $sql= "UPDATE `command` SET `nom`='$nom',`adresse`='$adresse',`num_tel`='$num_tel',`elements`='$elements',`prix`='$prix' WHERE id='$id'";
                        try {
                            $query=$con->prepare($sql);
                            $query->execute();
                            header("Location:command.php");
                        } catch (Exception $e) {
                            echo "Error " . $e->getMessage();
                            exit();
                        }
                        header("Location:command.php");
                        die;
                    }
                }
            }
        }

        public function g_c_statut($id)
        {
            $sql="SELECT * FROM command WHERE id =$id;";
            try {
                $con=config::getConnexion();
                // Create sql statment
                $query=$con->prepare($sql);
                $query->execute();
                $result = $query->fetch();
            } catch (Exception $e) {
                echo "Error " . $e->getMessage();
                exit();
            }
        }

        public function update_statut ()
        {
            if(isset($_GET['status'])){
                $id=$_GET['status'];
                $sql="SELECT * FROM command WHERE id =$id;";
            try {
                $con=config::getConnexion();
                // Create sql statment
                $query=$con->prepare($sql);
                $query->execute();
                $result = $query->fetch();
            } catch (Exception $e) {
                echo "Error " . $e->getMessage();
                exit();
            }
                 if($result['staut']==1){
                     $sql2="UPDATE `command` SET `staut`=0 WHERE id = $id;";
                     try {
                        $query=$con->prepare($sql2);
                        $query->execute();
                    } catch (Exception $e) {
                        echo "Error " . $e->getMessage();
                        exit();
                    }
                    header("Location:command.php");
                    die;
                 }else{
                     $sql3="UPDATE `command` SET `staut`=1 WHERE id = $id;";
                     try {
                        $query=$con->prepare($sql3);
                        $query->execute();
                        header("Location:command.php");
                    } catch (Exception $e) {
                        echo "Error " . $e->getMessage();
                        exit();
                    }
                    header("Location:command.php");
                    die;
                 }
            }
        }

        public function sortby()
        {
            if(isset($_GET['sort'])){
                $c=$_GET['sort'];
                try {
                    $con=config::getConnexion();
                    // Create sql statment
                    $sql = " select * from command order by $c";
                    $resultp = $con->query($sql);
                    return $resultp;
                } catch (Exception $e) {
                    echo "Error " . $e->getMessage();
                    exit();
                }

            }
        }
        
        public function search()
        {
            if(isset($_GET['search'])){
                $c=$_GET['search'];
                try {
                    $con=config::getConnexion();
                    // Create sql statment
                    $sql = "SELECT * FROM `command` WHERE `nom` LIKE '$c%' or `elements` LIKE '$c%' or `adresse` LIKE '$c%'";
                    $resultp = $con->query($sql);
                    return $resultp; 
                } catch (Exception $e) {
                    echo "Error " . $e->getMessage();
                    exit();
                }

            }
        }

    }




?>