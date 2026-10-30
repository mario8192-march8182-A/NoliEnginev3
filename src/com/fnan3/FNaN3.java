package com.fnan3;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;

import com.fnan3.engine.Scene;
import com.fnan3.engine.CameraSystem;


public class FNaN3 extends ApplicationAdapter {

    private SpriteBatch batch;

    private Scene currentScene;

    private CameraSystem camera;


    @Override
    public void create() {

        batch = new SpriteBatch();

        camera = new CameraSystem();


        // Carregar menu inicial
        currentScene = new Scene("MainMenu");

    }


    @Override
    public void render() {

        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);


        if(currentScene != null) {

            currentScene.update();


            batch.begin();

            currentScene.render(batch);

            batch.end();

        }

    }


    public void changeScene(Scene newScene) {

        currentScene = newScene;

    }


    @Override
    public void dispose() {

        batch.dispose();

        if(currentScene != null) {
            currentScene.dispose();
        }

    }

}
