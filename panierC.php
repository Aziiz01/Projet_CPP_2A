<?php 
    include_once 'config.php';
    //include_once 'C:\xampp\htdocs\transportz\model\chart.php';

    class panierC{
        public function add($idu){
            if(isset($_GET['add'])){
            $con=config::getConnexion();
            if($_SERVER['REQUEST_METHOD'] == "POST")
            {
                //something was posted
                $nomprod = trim($_POST['nomprod']);
                $qte     = (int) $_POST['qte'];
                $prix   = (float) $_POST['prix'];
                if(!empty($nomprod) && !empty($qte) && !empty($prix))
                {
                    //save to database
                    $sql = "INSERT INTO `panier`( `nom_prod`, `prix`, `qte`, `idu`) VALUES ('$nomprod','$prix','$qte','$idu')";
                    try {
                        $query=$con->prepare($sql);
                        $query->execute();
                        header("Location:chart.php");
                    } catch (Exception $e) {
                        echo "Error " . $e->getMessage();
                        exit();
                    }
                    header("Location:chart.php");
                    die;
                }
            }
        }
        }

        public function read($idu){
            try {
                $con=config::getConnexion();
                // Create sql statment
                $sql = "SELECT * FROM `panier` WHERE `idu` = $idu";
                $resultp = $con->query($sql);
                return $resultp;
            } catch (Exception $e) {
                echo "Error " . $e->getMessage();
                exit();
            }
        }

        public function delete(){
            if(isset($_GET['delete'])){
                $con=config::getConnexion();
                if(isset($_GET['delete'])){
                    $product_id = $_GET['delete'];
                    $sql ="DELETE FROM `panier` WHERE `id` = '$product_id' ";
                    try {
                        $query=$con->prepare($sql);
                        $query->execute();
                        header("Location:chart.php");
                    } catch (Exception $e) {
                        echo "Error " . $e->getMessage();
                        exit();
                    }
            }}
        }

        public function update(){
            if(isset($_GET['done'])){
                $con=config::getConnexion();
                if($_SERVER['REQUEST_METHOD'] == "POST")
                {
                    //something was posted
                    $id=(int) $_POST['id'];
                    $qte     = (int) $_POST['qte'];
                    if(!empty($qte) && !empty($id))
                    {
                        //save to database
                        $sql= "UPDATE `panier` SET `qte`='$qte' WHERE id='$id'";
                        try {
                            $query=$con->prepare($sql);
                            $query->execute();
                            header("Location:chart.php");
                        } catch (Exception $e) {
                            echo "Error " . $e->getMessage();
                            exit();
                        }
                        header("Location:chart.php");
                        die;
                    }
                }
            }
        }

    }




?>