// Code of ShenZhou
// Summer 9/12/96, qfy 5/99

#include <ansi.h>
#include "room.h"

inherit ROOM;

string* regions = ({
        "/d/changbai/",
        "/d/city/",
        "/d/dali/",
        "/d/emei/",
        "/d/forest/",
        "/d/foshan/",
        "/d/gaibang/",
        "/d/huanghe/",
        "/d/huashan/",
        "/d/jiaxing/",
        "/d/qilian/",
        "/d/quanzhou/",
        "/d/shaolin/",
        "/d/taihu/",
        "/d/taohua/",
        "/d/village/",
        "/d/wudang/",
        "/d/xingxiu/",
        "/d/xixia/",
        "/d/xueshan/",
        "/d/zhongnan/",
});

void create()
{
        set("short", "����");
        set("long", @LONG
һ���յ������η�������ͽ�к�ʵ��ǽ�ڡ��������ڵص׵�Ե�ʣ���������
�������е��ܲ��ˡ�
LONG
        );

        set("no_fight", 1);

        set("cost", 0);
        setup();

        call_out("free_victim", 1800);
}

int valid_leave(object me, string dir)
{
        if( me->query_temp("rysj_prisoner") ) {
                me->delete_temp("rysj_prisoner");
        }

        return ::valid_leave(me, dir);
}

int free_victim()
{
        string region, *rooms, room, place;
        object dest, *objs, *prisoners, luckyguy;
        int i, num;

        region = regions[random(sizeof(regions))];
        rooms = get_dir(region);

        if ( sizeof(rooms) == 0 ) {
                remove_call_out("free_victim");
                call_out("free_victim", 1);

                return 1;
        }

        room = rooms[random(sizeof(rooms))];

        if ( sscanf(room, "%s.c", room) ) {
                place = region+room;

                if ( !dest = find_object(place) )
                        dest = load_object(place);

                if ( objectp(dest) ) {
                        objs = all_inventory(this_object());
                        prisoners = allocate(sizeof(objs));

                        for ( i=0; i<sizeof(objs); i++ ) {
                            if ( objs[i]->is_character() && userp(objs[i]) ) {
                                prisoners[num] = objs[i];
                                num++;
                            }
                        }

                        if ( num > 0 ) {
                                luckyguy = prisoners[random(num)];

                                message_vision("���ε��ź�Ȼ���ˣ��������������ʿ���˽�����\n", luckyguy);
                                message_vision("���������ʿ����������һ�󣬱㳯$N���˹�����\n", luckyguy);
                                message_vision("һ�����������ʿ��$N�ٺټ�Ц������ү����������·��\n", luckyguy);
                                message_vision("�������������ʿͻȻһָ����$N�Ļ�˯Ѩ�ϡ�\n", luckyguy);

                                if( !wizardp(luckyguy) ) luckyguy->unconcious();

                                message_vision("���������ʿ��$N������������˳�����ȥ����Ҳ�������ˡ�\n", luckyguy);
                                luckyguy->move(dest);
                        }
                }
                else {
                        remove_call_out("free_victim");
                        call_out("free_victim", 1);

                        return 1;
                }
        
                remove_call_out("free_victim");
                call_out("free_victim", 1800);
        }
        else {
                remove_call_out("free_victim");
                call_out("free_victim", 1);
        }

        return 1;
}
