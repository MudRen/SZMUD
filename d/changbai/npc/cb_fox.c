// Code of ShenZhou
// huli.c

inherit NPC;

void create()
{
        set_name("����", ({ "fox" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ�������������ĺ���꣬�������������춯�������������˼���˫����\n");
        set("attitude", "peaceful");
        set("combat_exp", 10000);

        set("str", 40);
        set("dex", 60);

	set_temp("apply/attack", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/dexerity", 80);
        set_temp("apply/armor", 20);

        setup();
}

void init()
{
        ::init();

        if( interactive(this_player()) && living(this_object()) ) {
                remove_call_out("do_escape");
       	        call_out("do_escape", 3 + random(3));
        }
}

void die()
{
        object ob;

        message_vision("$N�Һ�һ�������ˣ�\n", this_object());
        ob = new(DRUG_D("hulipi"));
        ob->move(environment());
        destruct(this_object());
}

void do_escape()
{
       if( is_busy() || !living(this_object()) ) {
               call_out("huli", 10 + random(10));
               return;
       }

       message_vision("���꿴�����˹����ˣ���ಡ�������һ���굽���Աߵ��Ӳ��в����ˣ�\n", this_object());
       destruct(this_object());
}
