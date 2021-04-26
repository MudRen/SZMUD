// Code of ShenZhou
inherit NPC;

void create()
{
          set_name("雨儿", ({ "rain", "nu", "girl" }));

        set("long", 
      " 一个长的很好看的小姑娘.只是眉宇间有一丝哀怨. \n"); 
 set("gender", "女性");
          set("age", 23);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 3000);

        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);
        setup();
        set("chat_chance", 8);
        set("chat_msg", ({
"歌女低声轻吟,"梦醒时分，风冷叶飘地，遥望楚天，星辰零落"。\n",
"歌女低声轻吟,"怎奈人生似浮萍，来去间岁月如流，世事两茫茫"。\n",
"歌女低声轻吟,"忆故人，千里外江南水乡，旧游如梦"。\n",
"歌女低声轻吟,"难忘文期酒会，愿春风老后，秋月圆时，携君煮酒论英雄"。\n",


        }) );


	 carry_object("/d/city/obj/jin_ao.c")->wear();
        carry_object("/d/jiaxing/obj/yaoqin")->wield();

}


