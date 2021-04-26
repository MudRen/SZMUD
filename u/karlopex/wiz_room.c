// Code of ShenZhou 
// Room: /d/wizard/wiz_room.c 
// Athena 2002.5.25 

#include <ansi.h>
inherit ROOM; 
#include "/clone/misc/string.h"
string look_bian();
void init(); 
string update_here();

void create() 
{
        set("short", HIC "议事大堂" NOR);
        set("no_fight",1); 
        set("valid_startroom",1); 
        set("item_desc", ([
                "bian" : (: look_bian :),
                "poem" : "\n
      ┌─┐             ┌─┐
      │水│             │风│
      │车│             │扇│
      │车│             │扇│
      │水│             │风│
      │　│             │  │
      │水│             │风│
      │随│             │出│
      │车│             │扇│
      │　│             │  │
      │车│             │扇│
      │停│             │动│
      │水│             │风│
      │止│             │车│
      └─┘             └─┘
\n",
        ]));
        set("exits", ([ 
                "west" : __DIR__"wizard_room", 
        ])); 
        call_other("/clone/board/wizroom_b", "???"); 
        setup(); 
}

string look_bian()
{
       return
       "\n\n"
       "    ※※※※※※※※※※※※※※※※※※※※※※\n"
       "    ※※※※　　　　　　　　　　　　　　※※※※\n"       
       "    ※※※※    公    证    严    明    ※※※※\n"
       "    ※※※※　　　　　　　　　　　　　　※※※※\n"       
       "    ※※※※※※※※※※※※※※※※※※※※※※\n\n";
}


void init()
{
        object me = this_player(); 
        if (wizhood(me) == "(player)") 
        { 
                write(HIW "\n这不是你该来的地方\n\n" NOR); 
                me->set("startroom", "/d/death/death"); 
                me->move("/d/death/death.c"); 
                return 0; 
        } 
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
	if(!wiz_data=find_object("/clone/wiz/wiz_fpq2"))
		wiz_data=new("/clone/wiz/wiz_fpq2");
		
	if (!arg || arg == "") return notify_fail ("格式不对，请输入renwu help。\n");
	
	if ( arg == "help"){
		write(HIW"\n\nrenwu 命令格式如下：\n");
		write("renwu 部门代码 部门名称                 ------->设定部门。\n");
		write("renwu 部门代码 部门任务 -sr             ------->设定部门的任务。\n");
		write("renwu 部门代码 部门任务 -spr            ------->设定部门的任务（玩家可见）。\n");
		write("renwu 部门代码 部门工作完成情况 -jc     ------->设定部门的完成情况。\n");
		write("renwu 部门代码 部门工作完成情况 -jpc    ------->设定部门的完成情况（玩家可见）。\n");
		write("renwu ID 部门代码 职责                  ------->设定该部门的成员。\n");	
		write("renwu ID 部门代码 任务 -sr               ------->设定该部门成员的任务（最多可以设三个）。\n");
		write("renwu ID 部门代码 任务 -spr              ------->设定该部门成员的任务（最多可以设三个）（玩家可见）。\n");
		write("renwu ID 部门代码 完成情况 -jc           ------->设定该部门成员的任务完成情况。\n");
		write("renwu ID 部门代码 完成情况 -jpc          ------->设定该部门成员的任务完成情况（玩家可见）。\n");
		write("renwu 部门代码 delgrp                   ------->删除部门的所有资料。\n");
		write("renwu 部门代码 ID delcy                          ------->删除该成员的身份。\n"NOR);	
		write("renwu ID delwiz                         ------->删除该成员的所有任务。\n\n"NOR);	
		return 1;
	}
	if( sscanf(arg, "%s %s %s %s", wiz_c, grp_c, wiz_f, stat) == 4 ){
		text = setcolor(wiz_f);
		if (stat == "-jc"){
        		wiz_data->set_wizard_yinxiang(wiz_c, setcolor(wiz_f), grp_c, 1);
			tell_object(me, wiz_c+"的任务完成情况设定为"+setcolor(wiz_f)+"。\n");
		}else if (stat == "-sr"){
        		wiz_data->set_wizard_renwu(wiz_c, auto_e(text), grp_c, 1);
			tell_object(me, wiz_c+"的任务设定为"+auto_e(text)+"。\n");
		}if (stat == "-jpc"){
        		wiz_data->set_wizard_yinxiang(wiz_c, setcolor(wiz_f), grp_c, 2);
			tell_object(me, wiz_c+"的任务完成情况设定为"+setcolor(wiz_f)+"（玩家可见）。\n");
		}else if (stat == "-spr"){
        		wiz_data->set_wizard_renwu(wiz_c, auto_e(text), grp_c, 2);
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
	if(!wiz_data=find_object("/clone/wiz/wiz_fpq2"))
		wiz_data=new("/clone/wiz/wiz_fpq2");
	return "在这宽敞明亮的大会议室里，两旁摆设了几张红木桌椅，正墙上挂着一幅\n"
		+"<<百鸟朝凤图>>，画上方悬挂一横匾(bian)，东西有两根楹住，挂着一幅对联\n"
		+"(poem)，看起来十分气派。管理巫师通常都在这里讨论一些提案。\n\n"NOR
		+wiz_data->query_wizard_yinxiang(me)+"\n\n"
		+wiz_data->query_time()+"\n";
}