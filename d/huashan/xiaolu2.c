// Code of ShenZhou
// xiaolu2.c ��ɽ��ɽС·
// qfy 7/9/1996

inherit ROOM;

void create()
{
        set("short", "Сɽ·");
	set("long", @LONG
С·˳��ɽ��һ·���Ӷ�������ɽ��ɽ��˴��ǻ�ɽǰ������֮��
�����׼������˼���������ɽ�������ǲ��ô��У�Ҳ�������ˡ��Ϸ��ļ�
��С�ݣ����ǻ�ɽǰ���ľ�����
LONG
        );

        set("exits", ([ /* sizeof() == 2 */
	  	"northup" : __DIR__"xiaolu1",
		"west" : __DIR__"xiaozhu",
	]));

        set("objects", ([
                CLASS_D("huashan") + "/daizi" : 1, 
        ]));

	set("outdoors","huashan");

	set("cost", 2);
        setup();
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");

    if ( (!myfam || myfam["family_name"] != "��ɽ��") && dir == "west" 
    && objectp(present("shi daizi", environment(me))) )
           return notify_fail("ʩ������ס��˵����λʦ���治�����ͣ���ذɡ�\n");

    return ::valid_leave(me, dir);
}
