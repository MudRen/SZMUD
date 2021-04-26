// Code of ShenZhou
// 11/5/96. Ryu 
//1/20/98 Haowen
inherit F_UNIQUE;
inherit ITEM;
#include <ansi.h>
int do_open(string);
int do_suck(string);
int do_put(string);
void setup()
{}

void create()
{
        set_name(HIY "��ľ����" NOR, ({"shenmu wangding", "wangding"}));
        set_weight(35000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_clean_up", 1);
                set("long", "һ��������ϸ��Сľ����ľ�ʼ�������ľ��֮������������˿������\n"
			    "�����ͭǮ���Բ�ף�ľ���뾱����һ��ϸ�죬�ƺ����·�Ϊ���ء�\n");
                set("value", 10000000);
		set("sucked", 500);
        }
//        ::create();
}
void init()
{
   add_action("do_put","put");
   add_action("do_suck", "suck");
   add_action("do_open", "open");
   add_action("do_hua","hua");	
}
int do_open(string arg)
{
        object  ob, me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

               message_vision(HIG "$N��Сָ������ָ��ס�����Դ�ķָ����ָ��ס�ϰ�أ�����ת�˼�ת����ľ����\n"NOR, me);
	set_max_encumbrance(5000);
	set("opened", 1);
	set("long", "һ��������ϸ��Сľ����ľ�ʼ�������ľ��֮������������˿������\n"
            "�����ͭǮ���Բ�ף����Ǳ���������һ�ԡ�\n");
        return 1;
}
int is_container() { return 1; }
int reject(object ob)
{
        if (ob && ob->query("name") == "��" 
	|| ob && ob->query("name") == "��ȼ����") return 0;
        notify_fail("�㲻�ܰ����������Ž���ľ������\n");
        return 1;
}
int do_put(string arg)
{
	object ob, obj, me = this_player();
	string item, target;
        int amount;

	remove_call_out("open_up");
        if( !arg || sscanf(arg, "%s in %s", item, target) != 2 )
                return notify_fail("��Ҫ��ʲô�����Ž����\n");

        if( item == "all" ) {
                write("����һ��һ�����ɡ�\n");
                return 1;
        }
	if(query("opened") < 1)
		return notify_fail("ʲô��\n");

        sscanf(item, "%d %s", amount, item);

        if( !objectp(obj = present(item, me)) )
                return notify_fail("��Ҫ��˭ʲô������\n");

	if( obj->query("no_drop") ) {
                write("�������������뿪�㡣\n");
                return 1;
        }
	if( obj->name()=="��ȼ����") {
                message_vision( sprintf(HIY "$N��һ%s%s�Ž�%s��\n" NOR,
                        obj->query("unit"), obj->name(),
                        this_object()->name()),me );
		destruct(obj);
		me->add("combat_exp", 1+random(me->query_skill("poison")/3));

	if (NATURE_D->outdoor_room_event() == "event_dawn"
	&& interactive(me) && random(environment(this_object())->query("bing_can")) == 1){
	environment(this_object())->set("bing_can", 0);
	   remove_call_out("bing_can");
	   call_out("bing_can", random(30)+30, this_object());
	}

	else if ( interactive(me) && environment(this_object())->query("exits")) 
           call_out("open_up", random(20)+20, this_object());
	return 1;
	}
}

int do_suck(string arg)
{
        object me = this_player(), *ob;
	int i, tmp;

        if ( !arg || ( arg != "blood" ) )
                return notify_fail("ʲô��\n");

	if (query("suckable") < 1)
		return notify_fail("��Ҫ��ʲô��\n");

	if( environment(me)->query("no_fight") )
                return notify_fail("�㲻��������������¡�\n");

	if( me->is_fighting() )
                return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) 
	|| me->query_skill("lamaism", 1) || me->query_skill("mahayana", 1))
                return notify_fail("������ͺ¿ţ�����ǵ��ķ������ỹ��������\n");

	if ( me->query_skill("hunyuan-yiqi",1) || me->query_skill("lingji-zhuang", 1)
        || me->query_skill("huntian-qigong",1) || me->query_skill("xiaowuxiang", 1)
        || me->query_skill("taiji-shengong",1) || me->query_skill("zixia-gong",1)
	|| me->query_skill("dulong-dafa", 1) || me->query_skill("kurong-changong", 1))
                return notify_fail("�㲻��ɢ�˱����ڹ���������������\n");
       

        if (me->query("neili") < 30 || me->query("jingli") < 30
        || me->query("qi") < 30 || me->query("jing") < 30)
                return notify_fail("������������������衣\n");

        me->add("jing", (-1)*random(15));
        me->add("qi", (-1)*random(15));
        me->add("jingli", (-1)*random(15));
        me->add("neili", (-1)*random(15));

	message_vision(RED "$N���ֽ�ѪҺ��ס����ϥ�˹���\n"NOR, me);
	add("sucked", -1);

	if ((int)me->query_skill("poison", 1) > 30 && (int)me->query_skill("poison", 1) < 51)
        me->set_temp("muding1", 1);
	if ((int)me->query_skill("poison", 1) > 50 && (int)me->query_skill("poison", 1) < 101
	&& me->query("body_poison") > (int)me->query_skill("poison",1)/10)
        me->set_temp("muding1", 1);

        switch( random(3) )
        {
            case 0:
                if ( (int)me->query_skill("chousui-zhang", 1) > 30)
                {
                        me->improve_skill("chousui-zhang", me->query_int());
                        write("�㽫ѪҺ�������ڣ��������ơ���Ϊ�����ˡ�\n");
                        me->set_temp("muding_learned",1);
                        break;
                }
            case 1:
                if ( (int)me->query_skill("sanyin-zhua", 1) > 30)
                {
                        me->improve_skill("sanyin-zhua", me->query_int());
                        write("�����ָ����������һ������ɫ�����������צ����Ϊ�����ˡ�\n");
                        me->set_temp("muding_learned",1);
                        break;
                }
	    case 2:
		if (me->query_temp("muding1") || query("canblood") > 0 && me->query_skill("poison", 1) < 200)
                {
                        me->improve_skill("poison", me->query_int());
                        write("�����ϵĶ����ƺ�ͨ��������У���������������Ϊ�����ˡ�\n");
			me->delete_temp("muding1");
                        me->set_temp("muding_learned",1);
			break;
                }
        }
        if ( !me->query_temp("muding_learned") )
        {
        write("��о�һ�ɺ���Ϯ���������ж��ˡ�\n");
        me->apply_condition("insect_poison", 15);
        }
	ob = all_inventory(environment(me));

        tmp = 0;
        for(i=0; i<sizeof(ob); i++)
        {
                if ((string)ob[i]->query("race") == "����"  && ob[i] != me )
                {
                        message_vision(HIR "$N����˫�ֽ�סѪҺ����ϥ�˹�����ȻƳ����Χ���ˣ����һ����\n" NOR, me);
                        me->kill_ob(ob[i]);
                        ob[i]->fight_ob(me);
                        tmp = 1;
                }
        }
        if (tmp) return notify_fail("����ɱ����ڣ�\n");

	if(query("sucked") < 1){
        message_vision(RED "���ж�Ѫ�����θ��ˡ�\n"NOR, me);
	set("sucked", 500);
	set("suckable", 0);
	set("canblood", 0);
	set("long", "һ��������ϸ��Сľ����ľ�ʼ�������ľ��֮������������˿������\n"
            	    "�����ͭǮ���Բ�ף�ľ���뾱����һ��ϸ�죬�ƺ����·�Ϊ���ء�\n");
	return 1;
	}
	return 1;
}
int open_up(object room)
{
	object ob, obj = this_object();
	switch( random(2) )
        {
        case 0:
	ob=new("/d/xingxiu/npc/centipede");
	break;

	case 1:
	ob=new("/d/xingxiu/npc/scorpion");
	break;

	case 2:
	ob=new("/d/xingxiu/npc/spider");
        break;
        }
	ob->move(obj);
	message_vision(RED "�����õ����������죬ȴ��һֻ$N���˹�������$N�ŵ�����ɢ������������������ľ�����Ӷ��µĿ������ȥ���㲻�ٳ�����\n" NOR, ob, room);
	call_out("close_up", 20, obj, ob);
	return 1;
}
int bing_can(object room)
{
        object ob, obj = this_object(), me = this_player();
	message_vision(HIW "��������Ϯ�壬ֻ����������һ���������˹�����һ��������������������ǻ��ߣ�\n"
			   "����һ���ײϣ�����֮������ľ�Կݡ���ϳ洿������΢����ɫ����Ѱ���Ĳ϶�\n"
			   "����һ�����࣬����һ����򾣬����͸��ֱ��ˮ���������ŵ�����ɢ����������\n"
			   "����Ӷ��¿�������ȥ���㲻�ٳ�����\n"NOR, room);
	ob=new("/d/xingxiu/npc/bingcan");
	ob->move(obj);
	if (!me->query("wormbite")){ 
	me->set_skill("poison", me->query_skill("poison", 1) + 10);
	me->set("wormbite", 1);
	}
	set("canblood", 1);
	call_out("close_up", 20, obj, ob);
	return 1;
}
int close_up(object room, object ob)
{
        message_vision(RED "����һ���������ĳ��ӻ�����һ̲ŧѪ��\n" NOR, room);
        remove_call_out("open_up");
	set("long", "һ��������ϸ��Сľ����ľ�ʼ�������ľ��֮������������˿������\n"
    		    "�����ͭǮ���Բ�ס����Ǳ���������һ�ԣ�ֻ��������һ̲ʲô��\n"
		    "�ӻ��ɵ�Ѫ��һ�εδӿ��е�������\n");
	set("suckable", 1);
	destruct(ob);
        return 1;
}
int do_hua(string arg)
{
        object me = this_player(), *ob;
	int i, tmp;

        if ( !arg || ( arg != "blood" ) )
                return notify_fail("ʲô��\n");

	if (query("suckable") < 1)
		return notify_fail("��Ҫ��ʲô��\n");

	if( environment(me)->query("no_fight") )
                return notify_fail("�㲻��������������¡�\n");

	if( me->is_fighting() )
                return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) 
	|| me->query_skill("lamaism", 1) || me->query_skill("mahayana", 1))
                return notify_fail("������ͺ¿ţ�����ǵ��ķ������ỹ�ܻ�����\n");

	if ( me->query_skill("hunyuan-yiqi",1) || me->query_skill("lingji-zhuang", 1)
        || me->query_skill("huntian-qigong",1) || me->query_skill("xiaowuxiang", 1)
        || me->query_skill("taiji-shengong",1) || me->query_skill("zixia-gong",1)
	|| me->query_skill("dulong-dafa", 1) || me->query_skill("kurong-changong", 1))
                return notify_fail("�㲻��ɢ�˱����ڹ������ܻ�������\n");
	
	if ( me->query_skill("huagong-dafa",1)*me->query_skill("huagong-dafa",1)*me->query_skill("huagong-dafa",1)/10 > me->query("combat_exp"))
		{
		 me->apply_condition("hua_du",0);
		 me->apply_condition("huadu_poison",0);
		 return notify_fail("��Ŀǰ�ľ����޷�֧�ָ��ߵĻ����󷨣�\n");

		}
			       
	if ( me->query_skill("huagong-dafa",1) <120 )
		return notify_fail("�㻯���󷨹�������������ͨ��������������\n");
	

        if (me->query("neili") < 30 || me->query("jingli") < 30
        || me->query("qi") < 30 || me->query("jing") < 30)
                return notify_fail("������������������衣\n");

        me->add("jing", (-1)*random(15));
        me->add("qi", (-1)*random(15));
        me->add("jingli", (-1)*random(15));
        me->add("neili", (-1)*random(15));

	message_vision(RED "$N���ֽ�ѪҺ��ס����ϥ�˹������ж�Ѫ�������,������һ�����졣\n"NOR, me);
	add("sucked", -2);
	me->improve_skill("huagong-dafa", me->query_skill("poison",1)/10);
//	me->set_temp("muding_learned",1);
	me->apply_condition("huadu_poison",0);
        me->apply_condition("hua_du",1000);

//	me->start_busy(1);	
	
/*	if ( !me->query_temp("muding_learned") )
        {
        write("��о�һ�ɺ���Ϯ���������ж��ˡ�\n");
        me->apply_condition("insect_poison", 15);
        }*/
	ob = all_inventory(environment(me));

        tmp = 0;
        for(i=0; i<sizeof(ob); i++)
        {
                if ((string)ob[i]->query("race") == "����"  && ob[i] != me )
                {
                        message_vision(HIR "$N����˫�ֽ�סѪҺ����ϥ�˹�����ȻƳ����Χ���ˣ����һ����\n" NOR, me);
                        me->kill_ob(ob[i]);
                        ob[i]->fight_ob(me);
                        tmp = 1;
                }
        }
        if (tmp) return notify_fail("����ɱ����ڣ�\n");

	if(query("sucked") < 1){
        message_vision(RED "���ж�Ѫ�����θ��ˡ�\n"NOR, me);
        tell_object(me,HIR"�����ڶ��Կ�������ѹ�ƣ�һ��֮�ڱ������������������������������ƹأ�\n");

	set("sucked", 500);
	set("suckable", 0);
	set("canblood", 0);
	set("long", "һ��������ϸ��Сľ����ľ�ʼ�������ľ��֮������������˿������\n"
            	    "�����ͭǮ���Բ�ף�ľ���뾱����һ��ϸ�죬�ƺ����·�Ϊ���ء�\n");
	return 1;
	}
	return 1;
}
