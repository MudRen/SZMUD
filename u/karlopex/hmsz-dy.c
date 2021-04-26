/*-------------------------------------------------------------
** �ļ���: workroom.c
** Copyright (c) 2000-2001
** ������: Lisser
** ��  ��: 2001/08/03
** �޸���: Lisser
** ��  ��: 2001/08/10
** ��  ��: ����ɽׯ
**-----------------------------------------------------------*/

#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIC "����ɽׯ" NOR);
        set("long","�����ǻ���ɽׯ��Ժ�ӣ��˴�ֻ��һ��С�ݣ�����"+CYN"Ҷ��"NOR+"�ļң��ڽ���
��ǽ��һ���ܴ�ĵ�ͼ(map)���������˺ܶ�ķ��š�\n"
        );
        set("valid_startroom",1);

                                              
        set("exits", ([
                "th" : "/d/taohua/shuilong",
                "sl" : "/d/shaolin/guangchang1",
                "sn" : "/d/shenlong/tingkou",
                "xi" : "/d/xixia/dawu",
                "hz" : "/d/hangzhou/kedian",
                "wds" : "/d/wudang/sanqingdian",
                "xx" : "/d/xingxiu/xxh2",
                "gb" : "/d/gaibang/undertre",
                "gy" : "/d/taihu/qianyuan",
                "hs" : "/d/huashan/buwei1",
                "bt" : "/d/xingxiu/btyard",
                "dl" : "/d/dali/wangfu1",
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
                "yz" : "/d/city/guangchang",
                "qz" : "/d/quanzhou/zhongxin",
                "hs" : "/d/huashan/buwei1",
                "bt" : "/d/xingxiu/btyard",
                "dl" : "/d/dali/wangfu1",
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
                "wr" : "/d/wizard/wizard_room",
                "zn" : "/d/zhongnan/dajiaochang",
                "wg" : "/d/wuguan/zhengting",
                "enter": "/u/karlopex/workroom",
        ]));

        set("item_desc", ([
              "map" :
"
����������������������������������������������������������������
��                                                            ��
������ɽhs��Ȫ��qz������yz��̩ɽts������sl���䵱wds������ql   ��
����ؤ��gb������xx������em������bt��ѩɽxs���һ�th�� ����sn   ��
��������xi������gy������dl������hz��ȫ��zn, ��ʦwr�� ���wg   ��
������������������������������������������������������������  ��
����������������������������������������������������������������
\n",
          ]));

       set("outdoors", "karlopex");
       set("cost", 1);
       setup();
       //replace_program(ROOM);
}
void init()
{
		object me = this_player();
        if (getuid(me) == "karlopex")
{
                        add_action("do_promote", "promote");
                        add_action("do_edit", "edit");
}
		       	add_action("do_npc", "npc");
}

int valid_leave(object me, string dir)
{
        if (wizardp(me)) return ::valid_leave(me, dir); 
        if (!wizardp(me) && (dir == "yz" || (me->query("caninit") == "karlopex's workroom" && dir == "enter")) && getuid(me) != "karlopex")
        return ::valid_leave(me, dir);
        else return notify_fail(HIG"�ӣԣϣУ�����ȥ����㻹��ȥ����(yz)�ɣ�\n"NOR); 
}
int do_npc()
{
        string *dir, *dirx, roomx;
        object npc, room, me = this_player();
        int i, j;

        dir = get_dir("/d/");
        i = random(sizeof(dir) - 1);
		tell_object(me,HIC"\n���ڵ����Ŀ¼����"+chinese_number(i)+"��\n");
        dirx = get_dir("/d/"+dir[i]+"/");
        j = random(sizeof(dirx) - 1);
		tell_object(me,HIC"\n���ڵ�����ļ�����"+chinese_number(j)+"��\n");

        npc = new("/d/city/npc/liumang");
        roomx = "/d/"+dir[i]+"/"+dirx[j];
		tell_object(me,HIC"\n���ڵ����������"+roomx+"��\n");
		if (!objectp(npc)) tell_object(me,HIC"\nNPC error!\n");
        if ( !(room = find_object(roomx)) )
                room = load_object(roomx);
        npc->move(room);
        tell_object(me,HIG"\n"+npc->query("name")+"���ƶ���"+room->query("short")+"��\n"NOR);
        return 1;
}
int do_edit(string file)
{
	object me=this_player();
	if( !file ) return notify_fail("ָ���ʽ��edit <����>\n");

	if( in_edit(me) ) return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");

	seteuid(geteuid(me));
	ed(resolve_path(me->query("cwd"), file));
	return 1;
}
int do_promote(string arg)
{
        object ob, me = this_player();
        string promotee,old_status, new_status,new_site;
        int my_level, ob_level, level;
        string uid, *wiz, wizlist;
        int i;



//        if( wizhood(me) != "(admin)" && wizhood(me) != "(arch)" && me->geteuid() != "karlopex" ) return 0;

        if( !arg )      return notify_fail("ָ���ʽ��promote <ʹ����> <�ȼ�> <Access IP> or promote list\n");

        if(arg == "list")
        {
                write( SECURITY_D->query_wizlist() );
                return 1;
        }


        if( sscanf(arg, "%s %s %s", promotee, new_status,new_site) != 3 )
                if( sscanf(arg, "%s %s", promotee, new_status)!=2 )
                        return notify_fail("ָ���ʽ��promote <ʹ����> <�ȼ�> <Access IP>\n");

        if( wiz_level(new_status) <= 0 && new_status != "(player)" ) return notify_fail("û�����ֵȼ���\n");

        if( !objectp(ob = present(promotee, environment(me))) )
                ob = find_player(promotee);

        if( ob && !userp(ob) )
                return notify_fail("��ֻ�ܸı�ʹ���ߵ�Ȩ�ޡ�\n");

        if(!ob)
        {
                seteuid(getuid());
                ob = new("/clone/test/dummy");
                ob->set("id", promotee);
                if ( !ob->restore() )
                {
                        notify_fail("û�������ҡ�\n");
                }
                seteuid(getuid());
        }

        old_status = wizhood(ob);

        seteuid(getuid());
        if( !(SECURITY_D->set_status(ob, new_status,new_site,me->query("name")+"("+me->query("id")+")" )) )
                return notify_fail("�޸�ʧ�ܡ�\n");

        message_vision("$N��$n��Ȩ�޴� " + old_status + " ��Ϊ " + new_status + "�� ���ߵ�ַ��Ϊ: " + new_site + " ��\n", me, ob);
        seteuid(getuid());
        ob->setup();

        return 1;
}

