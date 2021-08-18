using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class RandomPos : MonoBehaviour
{

    [Header("Cubes Prefabs")]
    public GameObject[] cubePrefabs;
    private int cubeIndex;
    public int numberOfCubes = 5;
    private GameObject chosenCube;

    [Header("Spawn Points")]
    public GameObject[] SpawnPoints;
    private int spawnIndex;
    //Vector3 spawnTransform;
    Transform spawnTransform;


    [Header("Panel")]
    [SerializeField] GameObject panel;


    public List<GameObject> chosenCubes;
    public List<GameObject> cubesPresent = new List<GameObject>();
    private int timesPressed;
    public int correctTag;
    public int wrongTag;
    
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
    
    private float timePassed = 3;
    private int waitTime = 3;

    
    private void Update()
    {
        timePassed += Time.deltaTime;
        
    }
    public void checkTime()                /// this is for testing purposes woth the virtual button on the canvas
    {
        
        if(waitTime < timePassed )
        {
            StartGame();
            timePassed = 0;
        }
        
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    public void StartGame()
    {
        panel.SetActive(false);
        timesPressed++;
        chosenCubes = new List<GameObject>();

        SelectCubes();
        //add a timer to hide the (invoke)
        //Invoke("HideCubes", timePassed);
    }

    private void SelectCubes()
    {
        // set cube  tags to undefined
        foreach (GameObject cubeTag in cubePrefabs)
        {
            cubeTag.tag = "Untagged";
        }
        
        //remove previous gameobj in the list
        GameObject[] tagged = GameObject.FindGameObjectsWithTag("Chosen");
        foreach (GameObject obj in tagged)
        {
            Destroy(obj);
        }

        // add dificulty factor by changing the number of cubes
        if (timesPressed <= 3)
        {
            numberOfCubes = 2;
        }
        else if(timesPressed <= 6)
        {
            numberOfCubes = 3;
        }
        else if(timesPressed <= 9)
        {
            numberOfCubes = 4;
        }
        else if (timesPressed <= 12)
        {
            numberOfCubes = 5;
        }
        else if (timesPressed <= 15)
        {
            numberOfCubes = 6;
        }
        else if (timesPressed <= 18)
        {
            numberOfCubes = 7;
        }
        else if (timesPressed <= 21)
        {
            numberOfCubes = 8;
        }
        else if (timesPressed <= 24)
        {
            numberOfCubes = 9;
        }

        for (int i = 0; i < numberOfCubes; i++)
        {
            cubeIndex = Random.Range(0, cubePrefabs.Length);
            chosenCube = cubePrefabs[cubeIndex];
           
            // dont choose 2 times the same cube.
            while (chosenCube.tag == "Chosen")
            {
                cubeIndex = Random.Range(0, cubePrefabs.Length);
                chosenCube = cubePrefabs[cubeIndex];
            }
            chosenCube.tag = "Chosen";
           
            chosenCubes.Add(chosenCube);
        }
        SpawnTargets();

    }



    private void SpawnTargets()
    {
        //set tag and name to undefined
        foreach (GameObject posTag in SpawnPoints)
        {
            posTag.tag = "Untagged";
            posTag.name = "0";
        }
        
        
        foreach (GameObject cube in chosenCubes)
        {
            spawnIndex = Random.Range(0, SpawnPoints.Length);
            spawnTransform = SpawnPoints[spawnIndex].transform;
            while (spawnTransform.tag == "taken")
            {
                spawnIndex = Random.Range(0, SpawnPoints.Length);
                spawnTransform = SpawnPoints[spawnIndex].transform;
            }
            Instantiate(cube, spawnTransform.position, Quaternion.Euler(0,90,0));
            
            spawnTransform.tag = "taken";
            spawnTransform.name = cube.name;
        }
        CheckResults();
        Invoke("HideCubes", timePassed);
    }

    public void CheckResults()
    {
        foreach(GameObject spawnPointName in spawnTransform)
        {
            if (spawnPointName.name == Check.rfid1.ToString() || spawnPointName.name == Check.rfid2.ToString() || spawnPointName.name == Check.rfid3.ToString() ||
                spawnPointName.name == Check.rfid4.ToString() || spawnPointName.name == Check.rfid5.ToString() || spawnPointName.name == Check.rfid6.ToString() ||
                spawnPointName.name == Check.rfid7.ToString() || spawnPointName.name == Check.rfid8.ToString() || spawnPointName.name == Check.rfid9.ToString())
            {
                correctTag++;
            }
            else
            {
                wrongTag++;
            }
        }

        if (correctTag == numberOfCubes)
        {
            StartGame();
        }
        else if(wrongTag !=0)
        {
            restartGame();
        }
    }

    private void restartGame()
    {
        timesPressed = 0;
        chosenCubes.Clear();
        cubesPresent.Clear();
    }

    public void HideCubes()
    {
        panel.SetActive(true);
    }

    
}
