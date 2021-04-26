        //Created by Scatter
// Room: /u/scatter/workroom.c

#include <ansi.h>
#include <room.h>
//int do_gall();
inherit F_CLEAN_UP;
inherit ROOM;

void create()
{
        set("short", HIW"��ڤ����ĺ�լ"NOR);
        set("long", "������Ƿ�ڤ�ӵĺ�լ,Ŀǰ���Ǹ���"+HIW"��Ĺ�书"+NOR"����ʦ.\n��������(GO MOVIE), ���Ƿ�ڤ�ӵĵ�ӰԺ. �������ݵ�Ƭ������\n�䶯���ֵ�"+HIY"������"+NOR". ����"+YEL"��ڤ��"+NOR"����. ��"+MAG"��ʯ"+NOR"��������\nǽ���Ϲ���������������\n\n  �ɹ����Բ���żȻ��      \n\n            ���Ե�Ȩ�����¾��Եĸ���\n\n���������ڵĵ���ͨ��\n\n------------------------------------------------------\n��ɽhs��Ȫ��qz������yz��̩ɽts������sl���䵱wd������sn \nؤ��gb������xx������em������bt��ѩɽxs������kl������bj \n����xi������gy������dl������hz����Ĺgm����ʦwr�� \n\n���¹��ܣ����Դ� iget <����λ��>\n���¹��ܣ����Դ� gall <����λ��> (�ǵ� msg �� givemsg �趨���)\n\n------------------------------------------------------\n");
        set("exits", ([ /* sizeof() == 3 */
                  "hs"  : "/d/huashan/buwei1",
                  "qz"  : "/d/quanzhou/zhongxin",
                  "yz"  : "d/city/kedian",
                  "ts"  : "/d/taishan/fengchan",
                  "sl"  : "/d/shaolin/guangchang1",
                  "wd"  : "/d/wudang/shanmen",
                  "sn"  : "/d/shenlong/tingkou",
                  "gb"  : "/d/gaibang/undertre",
                  "xx"  : "/d/xingxiu/xxh2",
                  "em"  : "/d/emei/hz_guangchang",
                  "bt"  : "/d/xingxiu/btyard",
                  "xs"  : "/d/xueshan/guangchang",
                  "kl"  : "/d/shaolin/guangchang1",
                  "bj"  : "/d/beijing/changanjie",
                  "xi"  : "/d/xixia/dawu",
                  "gy"  : "/d/taihu/qianyuan",
                  "dl"  : "/d/dali/wangfu1",
                  "hz"  : "/d/hangzhou/kedian",
                        "note"  : "/u/scatter/note",
                  "gm"  : "/d/gumu/dating",
                  "wr"  : "/d/wizard/meeting_room",
                  "enter"  : "/u/scatter/lobby",
                                  "newjob" : "/u/snowlf/room/meeting_room",
                  "movie" : "/u/scatter/intromovie.c",
]));
        set("no_clean_up", 0);
        set("outdoors", "beijing");
        set("cost", 2);
    set("no_fight", "1");
    set("no_clean_up", "1");

//      set("objects", ([
//              "/clone/board/scatter_mb" : 1,
//      ]));

        setup();
        call_other("/clone/board/gumu_skill_mb", "???");
//      replace_program(ROOM);
}

void init() 
{ 
        object me=this_player();
                add_action("do_iget", "iget"); 
                                add_action("do_gall", "gall");
}

int do_iget(string arg)
{
        object me = this_player(), ob;

        if(!arg)
        {
                write("ʲô??\n");
                return 1;
        }

        if(me->query("id") != "scatter" && me->query("name") != "��ڤ��")
        {
                write("��û�õ���Ȩ����ʹ���������\n");
                return 1;
        }

        ob = new(arg);
        ob->move(me);
        write("��Ʒ������ϣ��벻Ҫ��Υ����;\n");
        return 1;
}


int do_gall(string what, object me)
{
    object ob, *ob_list, ob1;
    int i;
    string str;

        if(this_player()->query("id") != "scatter" && this_player()->query("name") != "��ڤ��")
    {
                write("��û�õ���Ȩ����ʹ���������\n");
        return 1;
    }
    
    if(!what) return notify_fail("ָ���ʽ gall ��Ʒ·��\n");
    
    if( sscanf(what, "%*s.c") != 1) return notify_fail("·�����Ϸ����޷��ҵ���Ʒ��\n");
    
    if( file_size(what) < 0 )
                return notify_fail("û���������(" + what + ")��\n");    
    
    seteuid(getuid());

    ob_list = users();

    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        ob1 = new(what);
        ob1 -> move(ob); 
        tell_object(ob, HIG "��ڤ��" + this_player()->query("givemsg") + "��\n" NOR);
                     
    }
    str = sprintf("���� %d λ��ҵõ���%s��\n", sizeof(ob_list), what->query("name"));    
    this_player()->start_more(str);
    return 1;
}
