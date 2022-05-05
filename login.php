<?PHP
include 'config.php';
function login()
{
	$con=config::getConnexion();
	if($_SERVER['REQUEST_METHOD'] == "POST")
	{
		//something was posted
		$nom = $_POST['nom'];
		if(!empty($nom))
		{

			//read from database
			$sql = "select * from utilisateurs where nomUtilisateur = '$nom' limit 1";
			try{  
				$query=$con->prepare($sql);
				$query->execute();
			}catch (Exception $e){
				die('Erreur: '.$e->getMessage());
			}
			if($query)
			{
					$user_data =  $query->fetch();
					{           
						$_SESSION['idUtilisateur'] = $user_data['idUtilisateur'];  
                		header("Location:shop.php");
						die;	
					}
			}
			
			echo "wrong password!";
		}else
		{
			echo "wrong useremail or password!";
		}
	}
}


function check_login()
{
	$con=config::getConnexion();
    if(isset($_SESSION['idUtilisateur']))
    {
        $id = $_SESSION['idUtilisateur'];
        $sql = "select * from utilisateurs where idUtilisateur =$id limit 1";
		try{  
			$query=$con->prepare($sql);
			$query->execute();
		}catch (Exception $e){
			die('Erreur: '.$e->getMessage());
		}
        if($query)
        {
            $user_data = $query->fetch();
            return $user_data;
        }
    }
    //redirect to login
    header("Location:login.php");
    die;

}


function logout()
{
	if(isset($_GET['logout'])){
	if(isset($_SESSION['idUtilisateur']))
{
	unset($_SESSION['idUtilisateur']);
}
header("Location: login.php");
die;
}
}

?>