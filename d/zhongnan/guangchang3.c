// Code of ShenZhou
///d/zhongnan/guangchang2.c �㳡
// sdong: 07/23/98

inherit ROOM;

void create()
{
		  set("short", "�㳡");
		  set("long", @LONG
��������������Ĺ㳡������������ש����ǰ����һ��̨�ף�ͨ��������
�������ǰ�и�����ߵĴ���¯����¯ǰ����̨�ϣ�������գ�����Ʈ�ơ���
�����м���С��ʿ���������������ǹ����
LONG
		  );
		  set("exits", ([
					 "south" : __DIR__"sanqing",
					 "north" : __DIR__"disan",
		  ]));

		  set("objects",([
					 CLASS_D("quanzhen") + "/cui" : 1,
        ]));

        set("outdoors", "zhongnan" );

        set("valid_startroom", 1);

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

