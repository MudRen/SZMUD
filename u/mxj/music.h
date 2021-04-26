// Code of ShenZhou
//music.h ����
#include <ansi.h>

int do_lianxi(string arg)
{
	string msg;
	object ob, me, where, weapon;
	int cost;

	string* zither_msg = ({
	"��ָ","��","����","����","����","���","��ע",
	"������","�","����","��ָ","��Բ","Ĩ��","����",
	});

	string* flute_msg = ({
	"��ָ", "����", "����","������", "��ָ����",
	});

	me = this_player();
	where = environment(me);
	weapon = me->query_temp("weapon");
        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

        if (where->query("sleep_room"))
                return notify_fail("��˯���ﲻ����ϰ�������������Ӱ�����ˡ�\n");

	if (where->query("no_fight"))
		return notify_fail("���ﲻ�ʺ���ϰ����������\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("���޷���ս����ר��������ϰ���࣡\n");

	if(!arg || !objectp(ob = present(arg, me)) )
		return notify_fail("��Ҫ��ϰ����ʲô��\n");

	if( !ob->query("shape") || 
	(ob->query("shape") !="flute" && ob->query("shape") !="zither"))
		return notify_fail("�㲻����ϰ����"+ob->name()+"��\n");

	if( ob != weapon )
		return notify_fail("�������װ��"+ob->name()+"��\n");

	if( (int)me->query_skill("music", 1) < 10 ) {
		if(ob->query("shape") =="zither")
		message_vision("$N�ָ�$n�����˼��£����ɵ�������������\n"NOR, me, ob);
		if(ob->query("shape") =="flute")
		message_vision("$N��$n���ڴ���һ�����������һ��������ȫ�����졣\n"NOR, me, ob);
		return 1;
	}

	if( (int)me->query("potential") < 1 )
                return notify_fail("���Ǳ���ѴＫ�ޣ�û�а취��������������\n");


	cost = 50 + random(40) * (40 - (int)me->query("int"))/20;
	if (cost < 10) cost = 10; // minimum cost

	if( (int)me->query("jing") > cost ) {
		if(ob->query("shape") =="zither") {
		msg = zither_msg[random(sizeof(zither_msg))] ;
		message_vision("$N�ָ�$n��������ϰ����"+msg+"���ļ��ɡ�\n"NOR, me, ob);
		if( me->query("family/family_name") == "�һ���" && (int)me->query_skill("music", 1) < 333 )
		me->improve_skill("music", me->query_int()*2 + 1);
		}
		else if(ob->query("shape") =="flute") {
		msg = flute_msg[random(sizeof(flute_msg))] ;
		message_vision("$N�ְ�$n�����촵�࣬ר����ϰ����"+msg+"���ļ��ɡ�\n"NOR, me, ob);
		if( me->query("family/family_name") == "�һ���" && (int)me->query_skill("music", 1) < 333)
		me->improve_skill("music", me->query_int()*2 + 1);

		}
		else return notify_fail("���󿴿����ҿ�����ʵ�ڲ�֪������������"+ob->name()+"��\n");
		}
	else {
		cost = me->query("jing");
		if (cost < 0) cost = 0;
		write("�����ڹ���ƣ�룬�޷�ר��������ϰ����������\n");
		return 1;
	}

	me->receive_damage("jing", cost/2, "�����ʴ�����");
	me->add("jingli", -cost/4);
	if(random(3) == 0) me->add("potential", -random(2));
	return 1;
}
