// Code of ShenZhou
///d/zhongnan/guangchang.c �㳡
// sdong: 07/23/98

inherit ROOM;

void create()
{
		  set("short", "�������㳡");
		  set("long", @LONG
�������������Ĺ㳡������������ש����ǰ����һ��̨�ף�ͨ��������
����ǰ�и�����ߵĴ���¯����¯ǰ����̨�ϣ�������գ�����Ʈ�ơ�
�㳡���м���С��ʿ���������������ǵ����
LONG
		  );
		  set("exits", ([
					 "south" : __DIR__"disan",
					 "east" : __DIR__"c_dlang",
					 "west" : __DIR__"c_xilang",
					 "northup" : __DIR__"dadian",
		  ]));

		  set("objects",([
                 CLASS_D("quanzhen")+"/ji" : 1,
		  ]));

		  set("outdoors", "zhongnan" );

		  set("valid_startroom", 1);

		  set("cost", 1);
		  setup();
}

