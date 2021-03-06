// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("歌女", ({ "ge nu", "nu", "girl" }));
        set("long", 
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

"歌女拨动着瑶琴低声唱道，“恨春去，不与人期，弄月色，空遗满地梨花雪”。\n",
"歌女垂首唱道，“农华如梦水东流，人间所事堪惆怅。莫向横塘问旧游”。\n",
"歌女引吭高歌，“相逢一醉是前缘，风雨散，飘然何处?”。\n",
"歌女低声轻吟，“衣上酒痕诗里字，点点行行，总是凄凉意”。\n",
"歌女低声悲歌，“惜起残红泪满衣，他生莫作有情疑。人天无地著相思”。\n",

        }) );


	 carry_object("/d/city/obj/jin_ao.c")->wear();
        carry_object("/d/jiaxing/obj/yaoqin")->wield();

}


