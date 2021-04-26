// Code of ShenZhou
// /d/emei/npc/monkey.c С����
// Shan 6/26/96

inherit NPC;

void create()
{
        seteuid(getuid());

        set_name("С����", ({ "monkey", "hou", "houzi" }) );
        set("race", "Ұ��");
        set("age", 2+random(3));
        set("long", "һֻ�����С���ӣ��۰Ͱ͵Ŀ����㣬�������Щ�Եġ�\n");
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����",  "ǰ��", "����", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("thief", 0);

        set_skill("stealing", 10+random(20));
	set_skill("dodge", 10+random(20));

        set("combat_exp", 350+random(200));
        set_temp("apply/attack", 6+random(8));
        set_temp("apply/defense", 6+random(4));
        set_temp("apply/armor", 2);

        setup();

        set("chat_chance", 8);
        set("chat_msg", ({
                "һֻС���Ӻ�Ȼ�ܹ������������˸�Ҿ��\n",
		"һֻС����ߴߴ�������˹�����\n",
		"С���ӱı��������ܿ��ˡ�\n",
                "С����ҡҡβ���ܿ��ˡ�\n",
                (: random_move :)
        }) );
}

int accept_object(object me, object obj)
{
        object obj2;

        if ( obj->query("food_supply") && obj->value() >= 0 ) {
           command("drop"+obj->query("id"));
           message_vision("С���Ӹ��˵ش�$N����ܿ��ˡ�\n", me);
           set_leader(me);
           say("С���������±��"+(string)obj->query("name")+"�Եøɸɾ�����\n");
           me->add("monkey", 1);

           remove_call_out("destroy_it");
           call_out("destroy_it", 1, obj);
           return 1;
        }
        else {
           say("С���Ӱ�"+(string)obj->query("name")+"���˹�������Ū�˼��£��ƺ�������ʲô�á�\n");
           command("shake");
           if (obj->query("money_id")) {
              obj2 = new(base_name(obj));
              obj2->set_amount((int)obj->query_amount());
              obj2->move(environment(me));
              say("С���Ӱ�"+(string)obj->query("name")+"�������ϡ�\n");
           }
           remove_call_out("drop_it");
           call_out("drop_it", 1, obj);
        }

        return 1; 
}

void drop_it(object obj)
{
        command("drop all");
}

void destroy_it(object obj)
{
        destruct(obj);
}


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
 
	if( !ob || environment(ob) != environment() 
                || ((fam = ob->query("family")) && fam["family_name"] == "����")
          ) return;

	switch( random(10) ) {
		case 0:
                       command("bow" + ob->query("id"));
		       break;
		case 1:
			command("steal kaoya from " + ob->query("id"));
			break;
		case 2:
                       command("jump" );
		       break;
		case 3:
                       command("steal jitui from " + ob->query("id"));	
                       command("eat jitui");
		       break;
		case 4:
                       command("steal jiudai from " + ob->query("id"));	
                       command("drink jiudai");
		       break;
                case 5:
                       command("steal chuan from " + ob->query("id"));
                       break;
                case 6:
                       command("steal hulu from " + ob->query("id"));  
                       command("drink hulu");
                       break;
                case 7:
                       command("steal tao from " + ob->query("id"));  
                       command("eat tao");
                       break;
                case 8:
                       command("fear ");
                       break;
                case 10:
                       command("steal bottle from " + ob->query("id"));  
                       command("drink bottle");
                       break;
	}
}

int is_grpfight()
{
	object me=this_object();
	object ob;
	int i;
	
	message_vision("��Χ��"+me->name()+"��$nȺ�����֮����\n\n", me, this_player());
	for (i=0;i<sizeof(all_inventory(environment(me)));i++)
		if (objectp(ob=present("monkey "+(i+1), environment(me))))
			ob->kill_ob(this_player());
	return 1;
}
