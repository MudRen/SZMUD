// Code of ShenZhou
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "��ʦ˯��");
	set("long", @LONG
���ǰ���ɽׯ��ʦ��ƽ����Ϣ��˯���������������Զ��ɳ�������
�����Ĵ�Įһ���޼ʡ����а�����ľ�Ƶ����Σ�һ�Ÿ��Űײ�����ľ����
��ǽ�ߡ�
LONG
	);
	set("sleep_room", 1);
	set("no_fight", 1);
	set("exits", ([ 
	    "east" : __DIR__"changlang4",
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
	object me;
	
	me = this_player();

	seteuid(getuid());

	if (me->is_busy())
		return notify_fail("����æ���أ�\n");

	if (me->query("family/family_name") != "����ɽ") {
		write("�㲻�ǰ���ɽ���ˣ�����˯�������\n");
		return 1;	
	}
	if (me->query("family/generation") > 3 ){
		write("������ʦ�ǵ�˯�������˲���˯�����\n");
		return 1;
		}
	if (me->query("family/generation") < 3 ){
		write("���Ϊ����������˯��ʦ�ǵ�˯����\n");
		return 1;
		}
	return 0;
}
