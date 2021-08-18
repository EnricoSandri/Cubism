using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using UnityEngine;
using System.Threading;


public class Check :MonoBehaviour
{
    public static int rfid1;
    public static int rfid2;
    public static int rfid3;
    public static int rfid4;
    public static int rfid5;
    public static int rfid6;
    public static int rfid7;
    public static int rfid8;
    public static int rfid9;
    public static int swicth;

    static bool checking = true;
    public static RandomPos rp;

    Thread readThread = new Thread(ReadData); 

    public static SerialPort sp = new SerialPort("COM3", 9600);

    // Start is called before the first frame update
    void Start()
    {
        OpenConnection();
        readThread.Start();
        rp = GetComponent<RandomPos>();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
    void OpenConnection()
    {
        if (sp != null)
        {
            if (sp.IsOpen)
            {
                sp.Close();
               
            }
            else
            {
                sp.Open();
                sp.ReadTimeout = 16;
               
            }
        }
        else
        {
            // Do nothing
        }
    }
    
    public static void ReadData()
    {
        
        sp.ReadLine();
        while (checking)
        {
            try
            {
                string[] splitSerial = sp.ReadLine().Replace("rfid:", "").Split();
                //splitSerial[0] = 1st rfid:, splitSerial[1] = 2nd rfid, splitSerial[2] = 3rd Sensor:  and so on.
                
                if (!int.TryParse(splitSerial[1].Replace("rfid ", ""), out rfid1)) print("Failed to parse Sensor 1");
                if (!int.TryParse(splitSerial[2].Replace("rfid ", ""), out rfid2)) print("Failed to parse Sensor 2");
                if (!int.TryParse(splitSerial[3].Replace("rfid ", ""), out rfid3)) print("Failed to parse Sensor 3");
                if (!int.TryParse(splitSerial[4].Replace("rfid ", ""), out rfid4)) print("Failed to parse Sensor 4");
                if (!int.TryParse(splitSerial[5].Replace("rfid ", ""), out rfid5)) print("Failed to parse Sensor 5");
                if (!int.TryParse(splitSerial[6].Replace("rfid ", ""), out rfid6)) print("Failed to parse Sensor 6");
                if (!int.TryParse(splitSerial[7].Replace("rfid ", ""), out rfid7)) print("Failed to parse Sensor 7");
                if (!int.TryParse(splitSerial[8].Replace("rfid ", ""), out rfid8)) print("Failed to parse Sensor 8");
                if (!int.TryParse(splitSerial[9].Replace("rfid ", ""), out rfid9)) print("Failed to parse Sensor 9");
                if (!int.TryParse(splitSerial[10].Replace("Swicth ", ""), out swicth)) print("Failed to parse Sensor 10");

                if (swicth == 1)
                {
                    rp.StartGame();
                }
            }
            catch (System.TimeoutException) { }

        }

    }

    private void OnApplicationQuit()
    {
        checking = false;
    }

}
