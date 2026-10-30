package core;

import java.util.ArrayList;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;


public class Scene {


    String name;

    ArrayList<GameObject> objects;


    public Scene(String name){

        this.name = name;

        objects = new ArrayList<>();


        // Exemplo:
        objects.add(new GameObject("Noli"));

    }



    public void update(){

        for(GameObject obj : objects){

            obj.update();

        }

    }



    public void draw(SpriteBatch batch){

        for(GameObject obj : objects){

            obj.draw(batch);

        }

    }

}
