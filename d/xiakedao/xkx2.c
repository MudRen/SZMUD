//Cracked by Roath
// xiakedao/xkx2.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 1;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����ڶ���ʯ�ң�ֻ����ǰһ�����˵��ǽ����ݺᡣ���˸��ֳ�
��������׽�Խ���������ײ�������������������ż������̲�һ
�ĶϽ���ǽ��Ҳ��Щ���������İߺۡ��Ա�����λ��������������ʲ
�ᡣʯ��(wall)���������ּ���
LONG );

      set("exits", ([
                "north" : __DIR__"xiakexing1",
      ]));
        set("item_desc",([
            "wall" : "
ǽ�����Ϸ����š��⹳˪ѩ�����������֡����ֵ��·������������
��������ǧС�֣��ʻ����죬��С��ͬ����һ���ǣ������ָ�������
�����⹳��������һ��д���ǣ��׾���ʫ�ƣ�������ֱ�۽�����ʤ��
ȫ������\n",
        ]));

        set("indoors", "xiakedao" );
	set("no_fight", 1);
        set("cost", 0);
        set("objects",([
            __DIR__+"npc/zhang.c" : 1,
            __DIR__+"npc/feng.c" : 1,
            ]));
        setup();


}
void init()
{
        ::init();
        add_action("do_study", "study");
}
#include "/d/xiakedao/xkx.h"
