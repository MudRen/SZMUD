//Cracked by Roath
// /d/xiakedao/npc/monkey.c ����
// Shan 6/26/96
// Ssy

inherit NPC;

void create()
{
        seteuid(getuid());

        set_name("С����", ({ "monkey", "hou", "houzi" }) );
        set("race", "Ұ��");
        set("age", 8);
        set("long", "һֻ����ĺ��ӣ��۰Ͱ͵Ŀ����㣬�������Щ�Եġ�\n");
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����",  "ǰ��", "����", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("thief", 0);

        set("combat_exp", 30);
        set_temp("apply/armor", 3);

        setup();

        set("chat_chance", 8);
        set("chat_msg", ({
                "һֻ���Ӻ�Ȼ�ܹ������������˸�Ҿ��\n",
		"һֻ����ߴߴ�������˹�����\n",
		"���ӱı��������ܿ��ˡ�\n",
                "����ҡҡβ���ܿ��ˡ�\n",
                (: random_move :)
        }) );
}

// inherit F_UNIQUE;

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("stealing");
		call_out("stealing", 1, ob);
	}
}

void stealing(object ob)
{
	mapping fam; 
 
	switch( random(10) ) {
		case 0:
                       command("bow " + ob->query("id"));
		       break;
		case 1:
                       command("xixi " + ob->query("id"));
		       break;
		case 2:
                       command("jump" );
		       break;
		case 3:
                       command("trip " + ob->query("id"));
		       break;
		case 4:
                       command("wanfu");
		       break;
                case 5:
                       command("trip" );
                       break;
                case 6:
                       command("claw");
                       break;
                case 7:
                       command("pat");
                       break;
                case 8:
                       command("fear");
                       break;
                case 9:
                       command("giggle" );
                       break;
                case 10:
                       command("wave" );
                       break;
	}
}


int accept_object(object me, object obj)
{
	if (obj->query("food_supply") && obj->value() >= 0) {
        	 command("bow "+ me->query("id"));
		 command("bite");
	}
        else {
        	 command("shake");
	         command("give " + obj->query("id") + " to " + me->query("id"));
		 obj->move(this_player());
        }
	return 1;
}

