// Code of ShenZhou
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
����һ�����򵥵ķ��䣬����ɽׯ�еļҶ����Ů�����˶���
������Ϣ����������ʮ���Ŵ��̣���Ϊ���Լ�˯���ĵط������ԼҶ�
���Ů��Ҳ����ɨ��ͦ�ɾ���
LONG
	);
	set("sleep_room", 1);
	set("no_fight", 1);
	set("exits", ([ 
	    "northeast" : __DIR__"liangongfang",
	]));

	set("cost", 1);
	setup();
}

void init()
{
	add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
	object me, where;
	
	me = this_player();
	where = environment(me);

	seteuid(getuid());

	if (me->is_busy())
		return notify_fail("����æ���أ�\n");

	if (me->query("family/family_name") != "����ɽ") {
		write("�㲻�ǰ���ɽ���ˣ�����˯�������\n");
		return 1;	
	}
	if (me->query("family/generation") < 4 ){
		write("��������˯���ĵط�����ʦ���и��õĵط�˯��\n");
		return 1;
		}
	if (me->query("family/generation") < 3 ){
		write("���Ϊ�������α�˯�����ǵ�˯����\n");
		return 1;
		}
	me->apply_condition("sleep", 2 + random(2));
	return 0;
}
