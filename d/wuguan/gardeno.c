//Created by Zyu on k1-08-13
// gardeno.c ��԰��

inherit ROOM;

void create()
{
        set("short", "��԰��");
	set("long", @LONG
��������ȥ����ݵĻ�԰��������󡣶�������ݵĴ��ţ�����Ӷ�
��ʱ�����Ƕ����ɡ����������ǰ������ݵĴ󲿷ֶ���ͨ��ǰ������
�ߵ���
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
            "west" : __DIR__"qianting",
            "east" : __DIR__"damen",
	    "south" : __DIR__"garden",	
        ]));

        set("no_clean_up", 0);
	set("no_steal", 1);
	set("sleep_room", 0);
        set("outdoors", "city" );

	set("cost", 1);
        setup();

}
