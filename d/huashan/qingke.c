// Code of ShenZhou
// qingke.c

inherit ROOM;

void create()
{
        set("short", "���ƺ");
	set("long", @LONG
�߹���᫵�ʮ���̣��������ţ��͵������ƺ�����ƺ��һɽ�����
��������Ϊƽ̹�������￪ʼ����ɽ��·������ԭ�������ʯ�ס�������
��ʯ��·����ʯ��������ʯ������ȥɽ�����գ��ο����ˣ��͸û�ͷ�ˡ�
ԶԶ����һ��ССʯͤ�����Ƕ���ͤ�ˡ��ഫ��̫���뻪��������������
�ˣ�����ɽ��Ϊ��ע����̫�����ˣ��Ӵ˻�ɽ�ϵ����ؾͲ������Ǯ����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"northdown" : __DIR__"shaluo",
  		"eastup" : __DIR__"qianchi",
	]));

        set("objects", ([
                __DIR__"npc/haoke" : 1,
		__DIR__"npc/youke" : 1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "huashan" );
        set("fjing", 1);
	set("cost", 2);
        setup();
        replace_program(ROOM);
}
 
