inherit NPC;
void create()
{       
        set_name("博弈行老板",({"boss","lao ban",}));
        set("nickname","祝君好运");
        set("long","他就是博弈行的老板。脸上挂着商人的招牌笑容。\n");
        set("age", 20);
        set("gender","男性");
        set("inquiry",([
                "彩票" : "你拥有的彩票可以交给招待来帮你对奖。\n",
                "皮囊" : "你问这里的招待要吧。\n",
                "彩票行": "这里是负责发行福利彩票和举行开奖，对奖，发奖活动的行当。\n",
        ]));    
        setup();

        carry_object("/clone/armor/cloth")->wear();
        set("chat_chance",1);
        set("chat_msg", ({
                "博弈行老板笑眯眯地说道：欢迎大家参与福利彩票开奖活动，祝你好运。\n",
        }) );
}

