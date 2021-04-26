// Code of ShenZhou
// boguang.c �ﲮ��
// qfy July 21, 1996

inherit NPC;

void create()
{
	set_name("�ﲮ��", ({ "tian boguang", "tian", "boguang" }));
	set("nickname", "�������");
	set("long", 
"�ﲮ������Ϊ�����г������õĲɻ���������ʶ��ɽ��������\n"
"��а������һ�ֿ쵶������������˫���Ṧ��������Ҳ��һ�ȵġ�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 30);
	set("shen", 0);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 150000);
	set("score", 5000);

	set_skill("force", 80);
	set_skill("dodge", 100);
	set_skill("parry", 80);
	set_skill("luan-blade", 100);
	set_skill("blade", 100);
	set_skill("unarmed", 80);
	set_skill("literate", 50);
	set_skill("ding-dodge", 100);
	set_skill("ding-force", 80);

	map_skill("dodge", "ding-dodge");
	map_skill("force", "ding-force");
	map_skill("parry", "luan-blade");
	map_skill("blade", "luan-blade");
	set("inquiry", ([
		"�����" : "�����������ƽ��һ֪����\n",
		"������" : "���ù��ң�����Ȼ�����ȥ������\n",
		"��ǰ��" : "���ù��ң�����Ȼ�����ȥ������\n",
		"������ǰ��" : "���ù��ң�����Ȼ�����ȥ������\n",
	]));

	setup();
	carry_object("/d/city/obj/gangdao")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

void init() 
{
	object ob, me = this_object();

	::init();
	if ( interactive(ob = this_player()) && !is_fighting() && !me->query_temp("said") ) {
	   me->set_temp("said", 1);
	   command( "say ���ҷ�ǰ������ɵ�ʤ���ҵĿ쵶��˵��");
	   remove_call_out("climb_tree");
	   call_out("climb_tree", 45, me); 	
	}
}

int accept_fight(object ob)
{
        object me = this_object();

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        return 1;
}

int checking(object me, object ob)
{
        int my_max_qi = me->query("max_qi");
	object weapon;

        if (me->is_fighting()) {
           if ( (me->query("qi")*100 / my_max_qi) <= 80 ) {
                command("exert recover");
           }

	   if ( !me->query_temp("attack_pending") 
	   && objectp(weapon = me->query_temp("weapon")) ) {
	   	me->set_temp("attack_pending", 1);
           	remove_call_out("fast_attack");
		call_out("fast_attack", 3, me, ob);
           }

	   if ( !me->query_temp("fought") ) {
		me->set_temp("fought", 1);
	   }

	   remove_call_out("climb_tree");
           call_out("checking", 1, me, ob);
           return 1;
        }

	if (!me->is_fighting()) {
		remove_call_out("fast_attack");
		remove_call_out("climb_tree");
                call_out("climb_tree", 30, me);
	}

	if (me->query("qi")*2 <= me->query("max_qi") 
	&& environment(me)->query("short") == "������" ) {
             me->remove_enemy(ob);
	     ob->remove_enemy(me);
	     environment(me)->add("tian_count", 1);
	     command( "say "+RANK_D->query_respect(ob)+"��Ȼ���������¶��е������������ȥ����ǰ����");
	     message("vision", ob->name() + "�����ﲮ���߽���ɽ�\n", environment(ob), ({ob}));
	     me->move("/d/huashan/yelin1");
	     ob->move("/d/huashan/yelin1");
	     tell_object(ob,"�ﲮ�������߹���ɽ��ɽ��һƬ��ɽҰ�֣���ע�⵽�Ƕ��ƺ��и�ɽ����\n");
	     me->move("/d/huashan/xiaojing1");
	     ob->move("/d/huashan/xiaojing1");
   	     tell_object(ob,"������ﲮ���������ã�����һ��С·��\n");
	     command( "bow" );
	     command( "say ��ǰ��ס���ɴ�·��ȥ���ǣ�����ʧ���ˡ�");
	     say("�ﲮ��˵���ͷҲ���ص����ˡ�\n");	
	     destruct(me);
             return 1;
	}

        if ( !present(ob, environment()) && me->query("attack_pending")==1 ) {
	   me->delete_temp("attack_pending");
           remove_call_out("fast_attack");
           return 1;
        }

        return 1;
}

int fast_attack(object me, object ob)
{
	int i, num;

	me->delete_temp("attack_pending");
	num = random(2)+3;

	message_vision("�ﲮ���һ����ʹ����쵶����������$N������"+chinese_number(num)+"����\n", ob);

	for (i=1; i<num+1; i++) {
	    COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	}

	return 1;
}

int climb_tree(object me)
{
	if ( environment(me)->query("short") == "������" ) {
	   if ( !me->query_temp("fought") ) {
	      environment(me)->add("tian_count", 1);	
	      message_vision("�ﲮ��ŭ����ǣ��ÿڴ�����������Ȼ����ݼ���ǰ�����ɰͰ͵ؽ��������������\n", me);
	      message_vision("�ﲮ����ű��������ϣ��ݼ��ܹ�ȥ�ˡ�\n", me);		
	   }
	   else {
	      message_vision("�ﲮ����˸���Ƿ��\n", me);
	      command("say ˡ�Ҳ��ܷ��㡣");
	      environment(me)->add("tian_count", 1);
	      message_vision("�ﲮ����ű��������ϣ��ݼ��ܹ�ȥ�ˡ�\n", me);
	   }
	}
	else {
	   message_vision("�ﲮ��Ҵ�ææ���뿪�ˡ�\n", me);
	}

	destruct(me);

	return 1;
} 
