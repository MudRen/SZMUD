//npc: /d/city/npc/shutong.c  书僮小月
//piao  2001/09/14
inherit NPC;
void create()
{       
        set_name("小月",({"xiao yue","xiao","shutong",}));
        set("title","天宝阁书僮");
        set("long","她长的胖乎乎的，有着一双丹凤眼，样子十分可爱\n");
        set("age", 14);
        set("gender","女性");
        set("inquiry",([
                "抄书":"桌上有很多草稿，你捡个位子坐下来抄(copy)吧。\n",
                "age":"我今年十四岁啦。\n",
                "学位":"这个呀，你要去问朱先生才知道。\n",    
                "科举":"你想考取功名呀，那就好好读书吧\n",
        ]));    
        setup();

        carry_object("/clone/armor/cloth")->wear();
        set("chat_chance",3);
        set("chat_msg", ({
                "小月说道：听老爷说，抄书可以增长不少知识。\n",
                "小月说道：在这里可以学到不少好东西哦。\n",
                "小月说道：我们老爷的学问可好啦。\n" ,                "小月说道：累了吧，要不要休息一下。\n",
                "小月往砚台里加了点水，使劲磨了起来。\n" ,        }) );

}

