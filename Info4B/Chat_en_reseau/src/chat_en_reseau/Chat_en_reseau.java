package chat_en_reseau;

import java.lang.Thread;

public class Chat_en_reseau 
{
    public static void main(String[] args) 
    {
        /*
        String[] port = new String[1];
        port[0] = "8080";
        String[] ip = new String[1];
        ip[0] = "127.0.0.1";
        try {
            ServeurMC.main(port);
            Thread.sleep(1000);
            for ( int i = 0 ; i < 5 ; i++ )
            {
                ThreadedClient.main(ip);
            }
        } catch (Exception ex) {
            System.out.println("Erreur");
        }
        */
        try
        {  
            Runtime.getRuntime().exec("cmd /c start cmd.exe && java ServeurMC"); 
        } 
        catch (Exception e) 
        { 
            e.printStackTrace(); 
        } 
    }
}
