//code of ����

#include <ansi.h>

inherit ROOM;

void create()

{
        set("short", HIC"��"NOR);
        set("long", @LONG
������һ���˹����ɵĵ��¿󳡡���������ʪ���࣬���ܵ�ǽ�ں͵��涼
�Ǻ�ɫһƬ������һ�ֲ�����ĸо����ڿ󳡵��������һյ���͵ƣ����Ƿ���
�����ڲɿ�ʱ������������ҹû�˵�ʱ���������ˮ����ڵ���ʱ�������δ�
���δ𡱵�������
LONG
        );

        set("possearch", 1);
        set("exits", ([ 
              "out":"/newjob/tiejiang/gate1",
			  "east":"/newjob/tiejiang/kuangchang",
			  "west":"/newjob/tiejiang/kuangchang1",

                      ])); 
		set("tjjob", 5);
        setup();
}
