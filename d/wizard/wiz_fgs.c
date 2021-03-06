//code for 神州
//巫师工作分配室
//create by Karlopex@sz
/*-------------------------------------------------------------------------
布武说道：我们现在有一个 renwu 命令。
布武说道：和 wizlist 配套。
你点了点头。
布武说道：不过我想那个东西只是给玩家看的巫师需要一个更专业的。
布武说道：在 wizard_room up 的地方
布武说道：room 直接可以看到。
你说道：在房间里查看？
你说道：直接？看到自己的？
布武说道：走到房间，直接就能看到。
布武说道：直接看到
布武说道：好像房间的描述一样。
你说道：是看到自己的还是全部的？
布武说道：全部的。
你说道：什么格式？
布武说道：首先是分几个组。
布武说道：有这个组的任务安排。
你说道：像侠客行现在的一样？
某人点了点头。
布武说道：对。不过我们是动态的。
布武说道：走到房间可以看到，使用 renwu 命令就能看到。
布武说道：走到房间可以看到，使用 renwu 命令就能修改。
布武说道：其他不同的 ..
布武说道：每个人可以有三个任务
布武说道：用 renwu lisser GLB 1 xxxx (备注)来输入命令
布武说道：用 renwu lisser GLB 1 xxxx (备注)
布武说道：用 renwu lisser GLB 2 aaaaa (备注)
布武说道：用 renwu lisser GLB 3 ttttt (备注)
布武说道：最好空的任务能够跳过。
你痛快地说道：好吧！
某人心疼地把你搂在怀里。
你说道：我先做个样品
布武说道：又给你这么麻烦的任务。
你倒在地上，像一根大木柱般直滚到一扇门边，咕碌碌的便滚了出去。
布武说道：下午能投入使用吗？
布武说道：晚上 ..
你说道：发完了才心疼我？
某人「嘻嘻嘻」傻笑了几声。
布武说道：不知道谁还能帮着做。
你说道：下午三点钟可以进行测试。
某人又惊又喜，叫道：「哇！叶枫弟弟，你好厉害哦！」
布武说道：ok.
某人点了点头。
你说道：那就没问题了。
布武说道：我们要加一个备注
布武说道：提醒一下。
你说道：备注写什么？
布武说道：比如说 动作太慢。进展不错。 等等。
--------------------------------------------------------------------------------------*/

#include <ansi.h>
#include "/clone/misc/string.h"
inherit ROOM;
string update_here();
void create()
{
	set("short", HIR"巫师工作分配室"NOR);
	set("exits", ([
		"ctrl"  : "/family_job/control.c",
		"up" : __DIR__"station_room",
		"down" : __DIR__"wizard_room" 	])
	);
        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("cost", 0);
        setup();
}
void init()
{
	object me = this_player();
        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
	if (getuid(me) == "lisser" || wizhood(me) == "(admin)" || wizhood(me) == "(arch)" ){
		add_action("do_renwu","renwu");
		add_action("do_renwu","fenpei");
	}
	set("long", update_here());
}
string auto_e(string text)
{
	string newtext;
        newtext = replace_string(text, "+", "\n");
        return newtext;
}

int do_renwu(string arg)
{
	string grp_c, grp_n, grp_rw, grp_f;
	string wiz_c, wiz_n, wiz_rw, wiz_f;
	string i, stat, text;
	object wiz_data, me = this_player();
	if(!wiz_data=find_object("/clone/wiz/wiz_fpq"))
		wiz_data=new("/clone/wiz/wiz_fpq");
		
	if (!arg || arg == "") return notify_fail ("格式不对，请输入renwu help。\n");
	
	if ( arg == "help"){
		write(HIW"\n\nrenwu 命令格式如下：\n");
		write("renwu 部门代码 部门名称                 ------->设定部门。\n");
		write("renwu 部门代码 部门任务 -sr             ------->设定部门的任务。\n");
		write("renwu 部门代码 部门任务 -spr            ------->设定部门的任务（玩家可见）。\n");
		write("renwu 部门代码 部门工作完成情况 -jc     ------->设定部门的完成情况。\n");
		write("renwu 部门代码 部门工作完成情况 -jpc    ------->设定部门的完成情况（玩家可见）。\n");
		write("renwu ID 部门代码 职责                  ------->设定该部门的成员。\n");	
		write("renwu ID <1/2/3> 任务 -sr               ------->设定该部门成员的任务（最多可以设三个）。\n");
		write("renwu ID <1/2/3> 任务 -spr              ------->设定该部门成员的任务（最多可以设三个）（玩家可见）。\n");
		write("renwu ID <1/2/3> 完成情况 -jc           ------->设定该部门成员的任务完成情况。\n");
		write("renwu ID <1/2/3> 完成情况 -jpc          ------->设定该部门成员的任务完成情况（玩家可见）。\n");
		write("renwu 部门代码 delgrp                   ------->删除部门的所有资料。\n");
		write("renwu 部门代码 ID delcy                          ------->删除该成员的身份。\n"NOR);	
		write("renwu ID delwiz                         ------->删除该成员的所有任务。\n\n"NOR);	
		return 1;
	}
	if( sscanf(arg, "%s %s %s %s", wiz_c, i, wiz_f, stat) == 4 ){
		text = setcolor(wiz_f);
		if (stat == "-jc"){
        		wiz_data->set_wizard_yinxiang(wiz_c, setcolor(wiz_f), i, 1);
			tell_object(me, wiz_c+"的任务完成情况设定为"+setcolor(wiz_f)+"。\n");
		}else if (stat == "-sr"){
        		wiz_data->set_wizard_renwu(wiz_c, auto_e(text), i, 1);
			tell_object(me, wiz_c+"的任务设定为"+auto_e(text)+"。\n");
		}if (stat == "-jpc"){
        		wiz_data->set_wizard_yinxiang(wiz_c, setcolor(wiz_f), i, 2);
			tell_object(me, wiz_c+"的任务完成情况设定为"+setcolor(wiz_f)+"（玩家可见）。\n");
		}else if (stat == "-spr"){
        		wiz_data->set_wizard_renwu(wiz_c, auto_e(text), i, 2);
			tell_object(me, wiz_c+"的任务设定为"+auto_e(text)+"（玩家可见）。\n");
		}else return notify_fail("格式不对，请输入renwu help。\n");
        }else if( sscanf(arg, "%s %s %s", grp_c, grp_f, stat) == 3 ){
		text = setcolor(grp_f);
		if (stat == "-jpc"){
        		wiz_data->set_group_yinxiang(grp_c, setcolor(grp_f), 2);
			tell_object(me, grp_c+"部门的任务完成情况设定为"+setcolor(grp_f)+"（玩家可见）。\n");
        	}else if (stat == "-spr"){
        		wiz_data->set_group_renwu(grp_c, setcolor(grp_f), 2);
			tell_object(me, grp_c+"部门的任务设定为"+auto_e(setcolor(wiz_f))+"（玩家可见）。\n");
		}if (stat == "-jc"){
        		wiz_data->set_group_yinxiang(grp_c, setcolor(grp_f), 1);
			tell_object(me, grp_c+"部门的任务完成情况设定为"+setcolor(grp_f)+"。\n");
        	}else if (stat == "-sr"){
        		wiz_data->set_group_renwu(grp_c, auto_e(text), 1);
			tell_object(me, grp_c+"部门的任务设定为"+auto_e(text)+"。\n");
		}else if (stat == "delcy"){
        		wiz_data->delete_wizard_chengyuan(grp_c, grp_f);
			tell_object(me, grp_c+"组"+grp_f+"的成员身份被删除了。\n");
		}else{
			wiz_data->set_group_chengyuan(grp_f, setcolor(stat), grp_c);
			tell_object(me, setcolor(grp_c)+"成为"+setcolor(grp_f)+"的"+setcolor(stat)+"。\n");
		}
	}else if( sscanf(arg, "%s %s", grp_c, grp_n)==2 ){
		if (grp_n == "delgrp"){
        		wiz_data->delete_group(grp_c);
			tell_object(me, grp_c+"部门被删除了。\n");
		}else if (grp_n == "delwiz"){
        		wiz_data->delete_wizard_renwu(grp_c);
			tell_object(me, grp_c+"的任务被删除了。\n");
		}else{
	        	wiz_data->set_group(grp_c, setcolor(grp_n));
			tell_object(me, grp_c+"部门的名称设定为"+setcolor(grp_n)+"。\n");
		}
        }else return notify_fail("格式不对，请输入renwu help。\n");
       	wiz_data->set_last(time());
	set("long", update_here());
       	return 1;
}
string update_here()
{
	object wiz_data, me = this_player();
	if(!wiz_data=find_object("/clone/wiz/wiz_fpq"))
		wiz_data=new("/clone/wiz/wiz_fpq");
	return HIC"这里是巫师工作分配室，这里的四周都是显示仪器，上面密密地写着在\n"
		"职巫师的名字，所在的工作组，相应的任务。\n\n"NOR
		+wiz_data->query_wizard_yinxiang(me)+"\n\n"
		+wiz_data->query_time()+"\n";
}