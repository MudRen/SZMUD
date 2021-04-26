// Code of ShenZhou
// zhandao1.c ������ջ��
// by Shan

inherit ROOM;

void create()
{
        set("short", "������ջ��");
	set("long", @LONG
������ջ���غ���������������һɽ�п������²������γ�һ��������ߣ�
���Ｘ���׵���Ͽ��������Ͽ��������ջ���ʹ���խ�İ���Ͽ��ת�۴�������
���ھ����ϡ�����ջ���ϣ�ֻ����խ��Σ�������������������ɽ����������
����ͷ���������϶���¿������ϡ�������쿪��ͼ�ġ�һ���졹��ջ����ͨ
ǧ���֣�����������
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"qingyin",
		"south" : __DIR__"zhandao2",
	]));

        set("no_clean_up", 0);
        set("fjing", 1);
        set("outdoors", "emei" );

	set("cost", 5);
	setup();
//	replace_program(ROOM);

}

int valid_leave(object me, string dir)
{
	if ( me->query_weight() >= 70000 && dir == "south") {
		tell_object(me, "��̫���ˣ������ϰ��쾢Ҳ��������һ���죬����������Ƥ��\n");
		me->receive_wound("qi", 5, me);
		return notify_fail("");
	}
	if ( me->query_encumbrance() >= 100000 && dir == "south") {
        	tell_object(me, "�����϶�������̫�࣬�����ϰ��쾢Ҳ��������һ���죬�����ö���һЩ��\n");
        	return notify_fail("");
	}

	return ::valid_leave(me, dir);
}

