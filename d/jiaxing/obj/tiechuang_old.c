//Cracked by Roath
// Jay 8/9/96
//changed by wzfeng@xkx 99/12/5

#include <ansi.h>
inherit ITEM;


void create()
{
        set_name("����", ({"tie chuang","chuang","bed"}));
        set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","����㿴��������Ϣ��˵��ϵͳС�����⣬��quit���ؽ�һ�飬��Ǹ��\n");
                set("unit", "��");
                set("material", "steal");
        }
        setup();
}


void init()
{
	object ob,kao;
        add_action("do_du", "du");
        add_action("do_du", "study");
        add_action("move_dianzi","move");
	add_action("do_sleep","sleep");
	add_action("do_look","look");
	add_action("do_look","l");
	add_action("do_dayun","dayun");
	add_action("do_sangong","sangong");
	add_action("do_break","break");

        if( interactive(ob = this_player()) ){
		remove_call_out("heibai_ask");
                call_out("heibai_ask",180,ob,3);
	}
	if(!present("liaokao",ob)) {
		kao = new(__DIR__"liaokao");
		kao->move(ob);
	}
	else call_out("zhenyun",3,ob);
	
}

void zhenyun(object ob)
{
//	ob->unconcious();
       message("system", 
          HIR "\n�����ǰһ�ڣ�����ʲôҲ��֪����....\n\n" NOR, ob);
	ob->disable_player(" <���Բ���>");
	ob->set("jing",0);
	ob->set("qi",0);
	ob->set("jingli",0);
	ob->set_temp("block_msg/all",1);        
	COMBAT_D->announce(ob, "unconcious");

        call_out("revive", random(100 - ob->query("con")) + 30,ob);
}

void revive(object ob)
{
        remove_call_out("revive");
        while( environment(ob)->is_character() )
                ob->move(environment(environment(ob)));
        ob->enable_player();
        COMBAT_D->announce(ob, "revive");
        ob->set_temp("block_msg/all", 0);
        message("system", HIY "\n������������������֪��....\n\n" NOR,
                ob);
        add_action("do_du", "du");
        add_action("do_du", "study");
        add_action("move_dianzi","move");
        add_action("do_sleep","sleep");
        add_action("do_look","look");
        add_action("do_look","l");
        add_action("do_dayun","dayun");
        add_action("do_sangong","sangong");
        add_action("do_break","break");

}

void heibai_ask(object ob, int t)
{
        object heibai;

	if(!objectp(ob)) return;
	if (environment(ob)->query("short") != "����") return;

        tell_object(ob,"\n\n\nͻȻ���⴫���Ų�����\n");

        if (ob->query("max_neili")==0 || t>0) {

        tell_object(ob,"ֻ������������˵������������������һ�仰��ÿ�������¾�����������"
        "��һ�Σ������һ�����仰�����������״𲻴���(dayun)����\n\n");
        ob->set_temp("dayun/can",1);
	remove_call_out("heibai_leave");
        call_out("heibai_leave",30,ob,t-1);
        }
        else {
        tell_object(ob,"ֻ������������˵�������������������᲻˵������\n");

        heibai=new("/d/jiaxing/npc/heibai2");
        heibai->move(environment(ob));
        message_vision("\n���ſ��һ�죬�߽�һ��������\n",ob);
	}
        return;
}

int do_dayun(string arg)
{
	object heibai;

	object me = this_player();
	if (me->query_temp("dayun/can")) {
	tell_object(me, "������˼�����˵����������������ͽ�������\n");
        heibai = new("/d/jiaxing/npc/heibai2");
        heibai->move(environment(me));
        message_vision("\n���ſ��һ�죬�߽�һ��������\n",heibai);
	remove_call_out("heibai_leave");
	remove_call_out("heibai_ask");
	return 1;
	}
	else return 0;
}



void heibai_leave(object ob, int t)
{
	if(!objectp(ob)) return;
	tell_object(ob,"ֻ�����������˵������Ȼ�����������ʣ����´���������\n\n");
	ob->set_temp("dayun/can",0);
	remove_call_out("heibai_ask");
	call_out("heibai_ask",250,ob,t);
	return;
}

int do_look(string arg)
{
	object me=this_player();

	if (!arg || !(arg=="chuang" || arg=="tie chuang" || arg=="bed"))
		return 0;

	if (!query("tieban")) {
	 	write("һ��Ӳ�����������������Ųݵ���(dianzi)��\n");
		return 1;
	}
	if (me->query_temp("tieslept")) {
		write("
һ��Ӳ�����������������Ųݵ��ӱ�����һ�ԣ�¶��������������������ּ���
������ţ�

    �Ϸ���ƽ�������ɱ�����飬���Ӻ��ף�����Ӧ��֮����Ψ�Ϸ���
    ���б���춴ˣ�һ��ͨ�쳹���񹦣��������Ϸ�ݹ�ͬ�࣬����С��
    ����֪�Ϸ�֮�ܣ��ຶ��Ҳ���Ƚ��Ϸ��񹦾���Ҫּ������춴ˣ���
    ��С��ϰ֮���е��ݺ����£��Ϸ����Ҳ��ࡣ

    ����֮�ᣬ����ɢ��(sangong)������������ֵ��Ϊ�㡣�����Ϳ���
    �����������ǿ֮���ա�
\n"
);
		return 1;
	}
	else {
		write("һ��Ӳ�������������ϵĲݵ���(dianzi)�ѱ�Ų��һ�ԡ�\n");
		return 1;
	}
}

int move_dianzi(string arg)
{
        object me = this_player();

        if (!arg || arg=="")
                return notify_fail("��ҪŲ��ʲô��\n");
        if (arg == "dianzi")
        {
          if (query("tieban")) {          
          write ("��Ѿ������Ĳݵ����̵������ϡ�\n");
	  say (me->name()+"�Ѿ������Ĳݵ����̵������ϡ�\n");
          set("tieban",0);
	  }
          else {
          write("��������ϵ��Ʋݵ��������¶�����������塣\n");
	  say (me->name()+"�������ϵ��Ʋݵ��������¶�����������塣\n");
          set("tieban",1);
          }
          return 1;
        }
        if (arg == "chuang" || arg=="bed" || arg=="tie chuang"){
                write("����̫���ˡ���Ų������\n");
                return 1;
        }
}

int do_sleep(string arg)
{
  object me = this_player();
  object where = environment(me);
  object *inv;
  int i;
  int normal;
  if(me->query_temp("sleeped"))
	  return 0;

  if (query("tieban") && !(me->query_temp("tieslept")==1)) {
        if (me->is_busy())
                return notify_fail("����æ���أ�\n");

        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
            if( inv[i]->query("equipped") 
		&& inv[i]->query("armor_type")=="cloth")
                i = sizeof(inv)+1;

        if (i==sizeof(inv)+2)
                normal = 1;
        else normal = 0;
  }
  else normal = 1;

        write("��������һ�ɣ���ʼ˯����\n");
        write("��һ�������ͽ��������硣\n");
		me->set_temp("sleeped",1);
        me->set_temp("block_msg/all",1);
        message_vision("$Nһ�������ڴ��ϣ���һ����������������������硣\n",me);
        where->add_temp("sleeping_person", 1);
        me->disable_player("<˯����>");

  if (normal) call_out("normal_wakeup",random(60 - me->query("con")), me, where);
	else call_out("wakeup",random(60 - me->query("con")), me, where);
  return 1;

}

void wakeup(object me,object where)
{
       object oldbed, newbed;

	if(!objectp(me)) return;
        while( environment(me)->is_character() )
                me->move(environment(environment(me)));
        me->enable_player();
        me->apply_condition("sleep", 8 + random(5));


        message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
		me->delete_temp("sleeped");
        me->set_temp("block_msg/all", 0);

        where->add_temp("sleeping_person", -1);

        write("��һ��˯�����ǳ��죬��ת��ʱ���پ���������ͻȻ֮�䣬��"
                "΢���ĵƹ��£�ֻ���Լ����ֱ���͹�����ĸ��֣����������"
                "�����б��������֡�\n");

        me->set_temp("tieslept",1);
        add_action("do_du", "du");
        add_action("do_du", "study");
        add_action("move_dianzi","move");
        add_action("do_sleep","sleep");
        add_action("do_look","look");
        add_action("do_look","l");
	add_action("do_dayun","dayun");
	add_action("do_sangong","sangong");
	add_action("do_break","break");

        return ;
}

void normal_wakeup(object me,object where)
{
        int sp, new_hp;

	if( !objectp(me) ) return;
        sp = 10 - (int)me->query_condition("sleep");
//      me->add("qi", (((me->query("eff_qi")) - me->query("qi"))*sp)/10 + 3);
        new_hp = (int)me->query("qi");
        new_hp += ((int)me->query("eff_qi") - new_hp)*sp/10;
        if (new_hp < 0) new_hp = 0;
        me->set("qi", new_hp);

        new_hp = (int)me->query("jingli");
        new_hp += ((int)me->query("max_jingli") - new_hp)*sp/10;
        if (new_hp < 0) new_hp = 0;
        me->set("jingli", new_hp);

        new_hp = (int)me->query("jing");
        new_hp += ((int)me->query("eff_jing") - new_hp)*sp/10;
        if (new_hp < 0) new_hp = 0;
        me->set("jing", new_hp);

        new_hp = (int)me->query("neili");
        new_hp += ((int)me->query("max_neili") - new_hp)*sp/20;
        if (new_hp < 0) new_hp = 0;
        me->set("neili", new_hp);

        while( environment(me)->is_character() )
                me->move(environment(environment(me)));
        me->enable_player();
        me->apply_condition("sleep", 8 + random(5));

        message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
        me->set_temp("block_msg/all", 0);
        write("��һ��������ֻ���������档�ûһ���ˡ�\n");

        //if (!where->query("sleep_room") && !where->query("hotel"))
                //where->delete("no_fight");

        where->add_temp("sleeping_person", -1);
        //me->delete("no_get");
        //me->delete("no_get_from");
        add_action("do_du", "du");
        add_action("do_du", "study");
        add_action("move_dianzi","move");
        add_action("do_sleep","sleep");
        add_action("do_look","look");
        add_action("do_look","l");
	add_action("do_dayun","dayun");
	add_action("do_sangong","sangong");
        add_action("do_break","break");

}

int do_sangong(string arg)
{
	object me = this_player();

	if (!me->query_temp("tieslept"))
	return 0;

	if( me->query_skill("huagong-dafa",1) < 30) {
	write("��Ļ����󷨻������Խ���ɢ����\n");
	return 1;
	}
	if(me->query("max_neili")==0) {
	write("���������ɢ��һ�ɶ�����ûʲ�����ɢ���ˡ�\n");
        return 1;
        }
	
	if(!me->query_temp("sangong_once")) {
	me->set_temp("sangong_once",1);
	write("ɢ����ζ�Ű��������ֵ��Ϊ�㡣������˼�����С�������϶�Ҫɢ��"
		"���ظ�һ������\n");
	return 1;
	}

	write("���ȫ������ɢ������˵������̩ͨ��\n");
	me->set("neili",0);
	me->set("mz_neili",me->query("max_neili"));
	me->set("max_neili",0);
	me->delete_temp("sangong_once");
	return 1;
}

int do_break(string arg)
{
	object me= this_player();
	object kao;

	if( !arg || arg=="" ) return 0;
	if (arg!="liaokao") return 0;

	if(!(kao=present("liaokao",me))) return 0;
	
	if (me->query("max_neili")>0) {
	write("��һʹ�����������������������۵û��ȥ��\n");
	return 1;
	}

	if (me->query("combat_exp")<500) {
	write("�㹦������������������\n");
        return 1;
        }

	write("��һʹ��������Ȼ�������ˡ�\n");
	destruct(kao);
	return 1;
}
int do_du(string arg)
{
	mapping skl;
        string *sname;
	int hglevel, i, k=0; 

        object me = this_player();
        if (!(arg=="tie chuang" || arg=="chuang" || arg=="bed"))
	return 0;

        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }
        if (!id(arg)) {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
	if (!query("tieban")) {
                write("�������Ųݵ����ء�\n");
                return 1;
        }
        if (!me->query_temp("tieslept")) {
		write("�������������ʲ��ö���\n");
                return 1;
	}

        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        if( (int)me->query("jing") < 35) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }

	if (me->query_skill("huagong-dafa", 1)>29){ 
	skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        for(i=0; i<sizeof(skl); i++) {
                if (SKILL_D(sname[i])->check() == "force")
		k++;
        	}
        if ( k >=2 ){ 
		write("�����ڲ�ͬ���������ײ����������������ڹ���\n");
		return 1;
		}
        }

	hglevel = me->query_skill("huagong-dafa", 1);
        if( (int)me->query("combat_exp") < (int)hglevel*hglevel*hglevel/10) {
		write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }

	if( hglevel > 30 && hglevel < 50) {
		write("��Ļ����󷨻���㣬������ѧ�����󷨣�\n");
		return 1;
        }

        if( me->query_skill("huagong-dafa", 1) > 119){
                write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
                return 1;
        }

	if( me->query_skill("force", 1)<10) {
		write("��Ļ����ڹ�����㣬����ѧ�����󷨡�\n");
		return 1;
	}

        if( me->query_skill("huagong-dafa", 1)>29 && 
	(me->query_skill("buddhism",1) || me->query_skill("taoism",1))) {
                write("��������ķ�ʹ�����ķ��֣���Ը��ѧ�����󷨡�\n");
                return 1;
        }

        me->receive_damage("jing", 35);
	me->improve_skill("huagong-dafa",
		me->query("int")*2/3+me->query_skill("literate",1)/10);
	write("���ںڰ������������壬���򻯹��󷨵�Ҫּ��\n");
        return 1;
}                         

