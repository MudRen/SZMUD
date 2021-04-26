// Code of ShenZhou
// ׯ��
inherit ITEM;
inherit F_UNIQUE;

void init();

void create()
{
	set_name("��ׯ�ӡ����", ({"zhujian", "bamboo" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
		else {
		set("value", 100);
		set("unit", "��");
		set("huiwen", 1);
		set("no_get", 1);
		set("no_steal", 1);
		set("no_drop", 1);
		set("long", 
		"һ����򣬼���Ϳ�˺��ᣬ������������������������д�����ܵĺ��֡�\n"
		"ͷһ���ǡ���ڤ���㣬����Ϊ���������ȥ����һƪƪ���ǡ�ׯ�ӡ���\n"
		"ֻ���м���һƬ��Щ��ͬ��ÿ�����Լ�������Ȧ�㣬��д�ż����Ż��ģ���˼�ǡ��Ƶ��ؾ������������\n");
		set("material", "bamboo");
	}
	setup();
	::create();
}

void init()
{
	add_action("do_lingwu", "lingwu");
}

int do_lingwu(string arg)
{
	mapping fam, skills, learned;
	object me;
	string skillname, msg;
	int skill_special, skill_basic, s, gain;

	me = this_player();
	skills = me->query_skills();
	learned = me->query_learned();


	if( base_name(environment(me)) != "/d/xingxiu/jadehall") 
		return notify_fail("���Ҷ���ţ����һ���е��¾䣬һ������������������������֮ʱ������������������Ŀ�ӣ���ֹ֪�������У�������������ȴ�������ϣ������Ȼ������\n"
		"�����뵽������Ϊ�٣�������΢���Ȼ�ѽ⣬����ί�أ��ᵶ������Ϊ֮�Ĺˣ�Ϊ֮�����־����\n�������룺��Ҫ��������ˣ����۾���Ҳ���ƣ�����΢΢һ�����Ͱѵ���ɱ�ˡ�����\n");
	
	if( me->query("combat_exp") < 1000000)
		return notify_fail("����ϵ��书����ܸ���㻹��������\n");

	if( !arg ) 
		return notify_fail("��Ҫ�����������ֻ����似��\n");

	if( arg == "force" )
		return notify_fail("����һ�Ѻ��ǣ���������Ҳ�������а�㾭�����е�ģ������������ڹ���\n");

	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("����뼤�������书���������������似��\n");

	skill_basic = me->query_skill(arg, 1);
	skill_special = me->query_skill(skillname, 1);

	if( skill_special < 200 )
		return notify_fail("���" + to_chinese(skillname) + "��δ�������޷��������" + to_chinese(arg) + "��\n");

	if( skill_basic > skill_special )
		return notify_fail("����" + to_chinese(skillname) + "�ϵ���Ϊ���㣬�޷���������" + to_chinese(arg) + "��\n");

	if( skill_basic < 1 )
		return notify_fail("�����û��ѧ������������ܰɣ� �����ȥ��̱��ˡ�\n");

	if ( me->query("jing") < 100 ) 
		return notify_fail("�����ھ��񲻼ѣ����򲻵�����еľ��塣\n");

	if( (int)me->query("potential") <= 1 )
		return notify_fail("���Ǳ���ѴＫ�ޡ�\n");

	me->receive_damage("jing", skill_basic/2 + random(skill_basic/2), "������ׯ�Ӵ��˳����������Ϣ");

	s = (1+random(3))*2;

	skill_special = skill_special * me->query("max_neili") * 2 / (1000 + me->query("max_neili"));

	  	if(s == 2) msg = "$Nϲ���������ڴ���ϵĺ����������㵸��������" + to_chinese(skillname) + "������֮����\n";
	  	else if(s == 4) msg = "ֻ��$N������һ�ߺ��ǵ����ƣ����㶯������������Ͷ��֮����Ю���磬�����" + to_chinese(arg) + "�������ϡ�\n";
	  	else msg = "$N˫��һ������һת������һ�ţ������赸һ�㡣\n";

		if( arg == "dodge") {
			if(s == 2) msg = "���$N����ֵ�����������ϥ�Ľ��ˣ��޲����ʩ�ɣ��������ֽ��ģ��ٶ���������һ�㡣\n";
			else if(s == 4) msg = "$N���ر��ۣ���ʱ����������ɬ����ʱԽ��Խ˳������������������ˮ��������ֹ��Ī���нڡ�\n";
			else msg = "$N����ǰ�У�����ת�ϣ������쳣��\n";
		}
		
	gain = skill_special/s + random(skill_special/(s/2));

	if(random(15) != 0) {
		me->add("potential", -1);
		me->improve_skill(arg, gain);
		if(wizardp(me) && s)
		tell_object(me,"s = "+s+", add "+ gain +" \n");
		message_vision(msg, me);
	}
	else {
		message_vision("$N�趯��һ�ᣬ����������һ�Ѻ��ǣ������������" + to_chinese(arg) + "����İ��أ�ȴһ�����á�\n", me);
		me->start_busy(1);
		me->add("potential", -1);
		me->receive_damage("jing", skill_basic/2 + random(skill_basic/2), "������ׯ�Ӵ��˳����������Ϣ");
	}

	if( me->query("potential") < 0) me->set("potential", 0);

	if( learned[arg] < 0 ) { 
		skills[arg]--;
		learned[arg] += skills[arg] * skills[arg];
	}

	return 1;

}
