// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "��Ϫ��");
        set("long", @LONG
���������������Ͻ���һ��С��ׯ�����Ӳ�����紾�ӡ��嶫��
һ����ͨ�ϱ��Ĵ���������л��˼ң�����С�߷���Ժ�ﲻʱ����ϰ��
��ߺ���������ӵ������и�Сɽ����
LONG
        );
        set("exits", ([
		"east" : __DIR__"road4",
		"west" : __DIR__"yard",
		"southup" : __DIR__"hill",
	]));

	set("objects", ([
		"/d/emei/npc/cow" : 1,
		"/d/xingxiu/npc/xiaoxiang-zi" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
