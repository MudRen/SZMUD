// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "�ּ��");
        set("long", @LONG
������һ���ּ�С���������������ѡ��������Ȫ�ݳǵ�
���ŵ��ţ������Ͽɴ����Ϲ㶫��
LONG
        );
        set("exits", ([
		"east" : "/d/quanzhou/xiqiao",
		"southwest" : __DIR__"qzroad6",
	]));

	set("objects", ([
                "/d/emei/obj/flower" : 1,
            "/d/shaolin/obj/caoliao" : 2,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
