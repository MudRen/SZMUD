// Code of ShenZhou
// tufeiwo0.c ����С·
// by Cleansword 1996/2/2

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
	������һ��Ƨ��������С·�ϣ���������ɭɭ�����֡�ֻ������ǰ�󣬵���
��������ǵص������֡���ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ
��������գ��������ڵ�˿��Ҳ�ޡ���˵���ﾭ�������˳�û�����ɾ�����
LONG
	);
        set("outdoors", "wudang");

	set("no_sleep_room",1);

	set("exits", ([
		"southup" : __DIR__"tufeiwo1",
		"northdown" : __DIR__"wdroad7",
	]));

        set("objects", ([
                __DIR__"npc/yetu" : 1 ]));

	set("cost", 1);
	setup();
}
