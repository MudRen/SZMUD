// Code of ShenZhou
// /d/taohua/npc/liuyun.c
#define BUSY_TIME 180

inherit NPC;
inherit F_MASTER;

string day_event() { return NATURE_D->outdoor_room_event(); }

string ask_job();

void create()
{
        set_name("流云", ({"liu yun","liu"}));
        set("long",
                "这是桃花岛主新收的闭门弟子，并教了他桃花岛的全部机关，\n"
                "他主要负责桃花弟子提高奇门遁甲只术。\n"
        );

        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 30);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 6500);
        set("max_jing", 3000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);
        set("combat_exp", 500000);
        set("score", 100);

        set_skill("force", 150);
        set_skill("bitao-xuangong", 150);
        set_skill("dodge", 150);
        set_skill("luoying-shenfa", 150);
        set_skill("finger", 150);
        set_skill("tanzhi-shentong", 150);
        set_skill("parry", 150);
        set_skill("qimen-dunjia", 300);
                set_skill("sword", 150);
        set_skill("yuxiao-jian", 150);

        map_skill("force", "bitao-xuangong");
        map_skill("dodge", "luoying-shenfa");
        map_skill("parry", "yuxiao-jian");
        map_skill("finger", "tanzhi-shentong");
                map_skill("sword", "yuxiao-jian");

        prepare_skill("finger", "tanzhi-shentong");

        set("inquiry", ([
                "学习" : (: ask_job :),
                "job" : (: ask_job :),
        ]));

        setup();

        carry_object("/d/taohua/obj/tiexiao")->wield(); 
        carry_object("/d/xixia/obj/robe")->wear();

}

string ask_job()
{
        object obj, place, *inv, me = this_player();

		if ( time() < me->query("mp_job_time") + BUSY_TIME ) 
		        return "我正忙着。";
                me->set("mp_job_time",time() ) ;


        if( (string)me->query("family/family_name") != "桃花岛" )
                return "你不是桃花岛的人，没有资格。";

        if( (int)me->query_skill("qimen-dunjia", 1) < 120 )
                return "你的奇门遁甲还不够，说了也白说。";

        if( me->query_condition("thjob") )
                return RANK_D->query_respect(me) + "已经在讨论奇门遁甲了。";

        command("ok");
        me->apply_condition("thjob", 3 + random(3));

        if( random((int)me->query_temp("lypoint")) > 1
        && !(present("pao", me)) ) {
                obj = new("/d/xixia/obj/robe");
                obj->move(me);
                message_vision("旁边一弟子拿出一件长袍让$N穿上。\n", me);
        }

        return "太好了，我正要找个人讨论一下奇门遁甲。";
}
