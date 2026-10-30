package core;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;

public class FNaNGame extends ApplicationAdapter {

    public SpriteBatch batch;
    public Scene currentScene;

    @Override
    public void create() {

        batch = new SpriteBatch();

        // Carrega o primeiro nível
        currentScene = new Scene("FNaN3_Night1");

    }


    @Override
    public void render() {

        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);


        if(currentScene != null){

            currentScene.update();

            batch.begin();

            currentScene.draw(batch);

            batch.end();

        }

    }


    @Override
    public void dispose(){

        batch.dispose();

    }
}
