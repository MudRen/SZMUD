// Code of ShenZhou
// shaluo.c ɯ��ƺ
// modified by qfy July 7, 1996

inherit ROOM;

void create()
{
        set("short", "ɯ��ƺ");
	set("long", @LONG
������Ȫ��̤������ʯ������ɽ�����ζ��ϣ���������ɯ��ƺ������
��ɽ·��ʼ���ͣ�����һ���ػ�������ɽ����������ʮ���̡���ͨ��ɽ��
�������������������֮��������춶��������и��ٲ���
LONG
        );

        set("exits", ([ /* sizeof() == 2 */
  	    "northwest" : __DIR__"path1",
  	    "southup" : __DIR__"qingke",
	    "northeast" : __DIR__"shanhong",
	]));

	set("objects", ([
		CLASS_D("huashan") + "/buyou" : 1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "huashan" );
        set("fjing", 1);

	set("cost", 2);
        setup();
        replace_program(ROOM);
}
 
