//piao 2001/10/16
//room: /d/wulin/dating.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Ӣ�۴���");
        set("long", @LONG
Ӣ�۴���������ͬ����Ϊ��ΰ�Ľ����������Ľ����ĸ��޴��ʯ��֧
�ţ����ڵ���������ʮ֧��֦���Ļ�ѣ�����ƻ�ͨ�����������������
����ʯ���м�һ��ո�µĺ��̺����̺�ľ�ͷ����һ�Ž�ڻԻ͵����ӣ�
���Ӻ����ǽ��д��һ�����ġ��塱�֡�����ͬ�˵���ּ���Ǹ����塱
�֣��������ƣ�����ȡ�塣������Χ���Ǻ�����ĸ��񣬼�¼��ǰ��Ӣ��
�����Ʒ����Ӣ���¼���ֻҪ��Ŭ��������¼�Ҳ���ܽ�����Щ����Ϊ
����Ӣ����������
LONG
        ); 
       
        set("exits",([
                "north" : __DIR__"houyuan",                 
                "south" : __DIR__"zhengqiting",
                "west" : __DIR__"shishe",                 
                "east" : __DIR__"jiulu",
        ]));   

        set("objects",([
                __DIR__"npc/yishi1" : 1,
        ]));
                set("no_fight", "1");
                set("cost", 1);
                setup();
//              replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
       
        object *inv;
        int i;
        inv = all_inventory(me);//����me�������е���Ʒ
        if( dir == "north"&&!wizardp(me)) { 
                if(!me->query_temp("houyuan") )
                return notify_fail(CYN"����ͬ����ʿ��ס�㣬˵�������²�û�ܵ����˵�����, ���ý����԰, ������ذɡ�\n"NOR);
;
      }      
        for (i=0; i<sizeof(inv); i++) {  
                if (inv[i]->is_character())
                return notify_fail(CYN"�㲻�ܴ���������ҽ�ȥ��\n"NOR);
       
        }         

//      me->delete_temp("houyuan");
        return ::valid_leave(me, dir);
}             

