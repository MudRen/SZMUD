// Code of ShenZhou
// Room: /city/shuyuan.c
// YZC 1995/12/04 
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"��Ժ"NOR);
        set("long", @LONG
��������Ժ�Ľ��ã�����������һ����Ⱦ��һλׯ���������������̫ʦ��
�Ͻ�ѧ���Ǿ��ǵ�������������ˡ�������������������ѧ��ѧ����һ�Ź��ⰻ
Ȼ���鰸������������ǰ�棬���ϰ��ż��������˵���װ�鼮����������������
һ����ܡ������ڶ��������ʯ�̣������Ժ��ʷ���ƾá�ֵ��һ�����Ƕ�ڽ�
��ǰ��ڵ�ѧ��(xuegui)���ұڵ�֤��(zhengshu)��
LONG
        );

        set("exits", ([
                "south" : __DIR__"dongdajie1",
                "up": __DIR__"cangshuge",
        ]));

        set("item_desc", ([
                "xuegui" : "�ս����������տ���Ŀ��ҳ��"  
                        "\nͨ��ʱ���������ζ�����ʫ����" 
                        "\n���������ʣ���ΰ�ʱ���ꡣ"
                        "\nҹ���Խ���������Ҫ������\n\n"
                        "��ѧ���ѧ�Ѷ�����Ǳ�����ļӱ���\n",
                "zhengshu" : "��ʦ���Ӽ���Ȩ�ٰ�ƾٿ��������ѧλ��"
                             "����������������������춿ƾټ��ʹ�ð���"
                             "(help keju)��\n",
        ]));
        
        set("objects", ([
                __DIR__"npc/zhu": 1,
        ]));

        set("day_shop", 1);
        set("cost", 0);
        setup();
}

int valid_leave(object me, string dir)
{
      object *inv;
        int i;
        inv = all_inventory(me);
	   if ( dir == "south" || dir == "up" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (userp(inv[i]))
                        return notify_fail("�㲻�ܴ�����������뿪���\n");
                }
        }
	   me->set_temp("mark/��", 0);
        return ::valid_leave(me, dir);
}