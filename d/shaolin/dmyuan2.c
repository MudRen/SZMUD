// Code of ShenZhou
// Room: /d/shaolin/dmyuan2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "��ĦԺ��¥");
	set("long", @LONG
����һ�����ӵĵ��á����׵�ǽ�Ϲ����˸����书ͼ�ף���
�ٰ����ü����ɮ����������ͼ�׻���֮ǰ���ƺ��ڿ��˼����
�ϱ�ɽǽ�Ǹ߼��ݶ��Ĵ���ܣ��߽�ϸ���������Ǹ��Ÿ��ɵ���
�����ţ������а��ż��Ű����ͼ������ţ���λ��ɮ�����붨�С�
LONG
	);

	set("exits", ([
		"down" : __DIR__"dmyuan",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/xuan-bei" : 1,
		__DIR__"npc/xiao-bei" : 1,
	]));
	set("cost", 1);
	setup();
}

void init()
{
	add_action("do_understand", "understand");
	add_action("do_understand", "lingwu");
}

int do_understand(string arg)
{
	mapping fam, skills, learned;
	object me;
	string skillname;
	int skill_special, skill_basic;

	me = this_player();
	skills = me->query_skills();
	learned = me->query_learned();

	if( !me->query("luohan_winner") )
		return notify_fail("����˵�����㼶�𲻹��������ڴ�ĦԺ����ޡ�\n");

	if( mapp(fam = me->query("family")) 
	&&  fam["family_name"] == "������" 
	&&  fam["generation"] > 37  )
		return notify_fail("����˵�����㼶�𲻹��������ڴ�ĦԺ����ޡ�\n");

	if( !arg ) 
		return notify_fail("��Ҫ�о����ֻ����似��");

	if( arg == "force" )
		return notify_fail("�㲻���������������ڹ���\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("������������书����������似��������\n");

	skill_basic = me->query_skill(arg, 1);
	skill_special = me->query_skill(skillname, 1);

	if( skill_special < 1 )
		return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
	if( skill_basic > skill_special )
		return notify_fail("��" + to_chinese(skillname) + "�����������޷���������" + to_chinese(arg) + "��\n");
	if( skill_basic < 1 )
		return notify_fail("�����û��ѧ������������ܰɣ� �����ȥ��̱��ˡ�\n");

	if ( me->query("jing") < 100 ) 
		return notify_fail("�����ھ��񲻼ѣ��޷���������˼����\n");

	if( (int)me->query("potential") <= 1 )
		return notify_fail("���Ǳ�ܲ��㣬�޷���������书��\n");

	me->receive_damage("jing", random(skill_basic), "�ڴ�ĦԺڤ˼������Դ��������ˣ��װ׵��Խ�����һ��");
	if( me->query("potential") < 0) me->set("potential", 0);

  // modified by aln here to show the importance of max jing
        skill_special = skill_special * me->query("max_jing") * 2 / (1000 + me->query("max_jing"));

	if(random(20) == 0) {
		me->add("potential", -2);
		me->improve_skill(arg, skill_special + random(skill_special*2));
		write( "ֻ�����л�Ȼ���ʣ����" + to_chinese(arg) + "�������ֽ���һ�㣡\n" );
	}
	else if(random(10) == 0) {
		me->add("potential", -1);
		me->improve_skill(arg, skill_special/2 + random(skill_special/1));
		write( "��ڤ˼���룬��" + to_chinese(arg) + "��������һ����ᣡ\n" );
	}
	else if(random(5) == 0) {
		me->add("potential", 0);
		me->improve_skill(arg, skill_special/4 + random(skill_special/2));
		write( "�����ֱȻ��ţ��ƺ���" + to_chinese(arg) + "�еļ�������������ᡣ\n" );
	}
	else if(random(2) == 0) {
		me->improve_skill(arg, skill_special/8 + random(skill_special/4));
		write( "������������Ǳ�Ŀ�˼" + to_chinese(arg) + "�ϵ��ѽ�֮����\n" );
	}
	else if(random(5) == 0) {
		write( "������˵�����ķ����" + to_chinese(arg) + "ʼ�ղ���һ�⡣\n" );
	}
	else if(random(10) == 0) {
		me->improve_skill(arg, - (skill_special/10 + random(skill_special/5)));
		write( "��ֻ�������������Ҵܣ�" + to_chinese(arg) + "�е���ʽ�������һ������ǰ���֣�\n" );
	}
	else if(random(20) == 0) {
		me->improve_skill(arg, - (skill_special/6 + random(skill_special/3)));
		write( "��Ĵ�����һƬ�հס���" + to_chinese(arg) + "��Խ��Խ��Ϳ��\n" );
	}
	else {
		write( "������������Ǳ�Ŀ�˼" + to_chinese(arg) + "�ϵ��ѽ�֮����\n" );
	}

	if( learned[arg] < 0 ) { 
		skills[arg]--;
		learned[arg] += skills[arg] * skills[arg];
	}

	return 1;

}

