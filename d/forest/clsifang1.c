//Cracked by Yujie
// changle/clsifang1.c

inherit ROOM;

#include <ansi.h>

#define SIFANG "/d/forest/sifang/sifang1_file"
#define DDR "/d/forest/"

void create()
{	string msg;
	set("short", "龙灵堂香主私房");
        if (file_size(SIFANG) < 1 )
        	set("long","这是一个空空如也的新屋。\n");
        else
        	set("long",read_file(SIFANG));
        
        set("exits", ([
		"west" : DDR + "clhoulang1",
        ]));
	
        set("object",([
        	DDR+"npc/shicong" : 1,
        ]));
        
        set("can_sleep", 1);
        
        set("no_clean_up",1);
        set("valid_startroom", 1);

        
        set("no_steal", 1);

        set("cost", 0);

        setup();
       
}

void reset()
{
	::reset();
	set("no_clean_up",1);
	return;
}

void init()
{
	object me=this_player();
	string pos;
        
        if (stringp (pos = me->query("clbpos")) && (pos != "龙灵堂"))
        {	call_out("pos_leave",1,me);
        	return;	
        }
        
        if (!stringp (pos = me->query("clbpos")) && (me->query_temp("invite")!= "龙灵堂"))
        {	call_out("other_leave",1,me);
        	return;	
        }
              
        add_action("do_get", "get");
        add_action("do_invite","invite");
        add_action("do_invite","yaoqing");
        add_action("do_modify","modify");
        add_action("do_nofight","nofight");
        add_action("do_canfight","canfight");
}

int do_get(string arg)
{
        object obj;
        string usr;
        
        
        if( arg
        && objectp(obj = present(arg, environment(this_player())))
        && userp(obj) ) {
                write("你不能搬动玩家的身体。\n");
                return 1;
        }
        
        if ( (sscanf(arg,"%*s from %s",usr) == 2)
        && objectp (obj = find_player(usr))
        && userp (obj) )
        {
        	write("你不能在这里搜玩家的身体。\n");
        	return 1;
        }
        return 0;
} 

int do_invite(string arg)
{
	object ob;
	object me = this_player();
	
	if ( !stringp(me->query("clbpos")) || me->query("clbpos")!="龙灵堂")
	{	write("你不是这里的主人，不能擅自邀请别人。\n");
		return 1;
	}        		

	if ( arg
	&& objectp (ob = find_player(arg))
	&& userp (ob) )
	{	
		ob->set_temp("invite","龙灵堂");
		write("已经帮你邀请了"+ob->query("name")+"。\n");
		tell_object(ob,HIM"【邀请】：" + "长乐帮龙灵堂香主 " + me->query("name")+"邀请你去他的香主私房。\n"NOR);
		return 1;
	}
	
	if ( arg && !objectp (ob = find_player(arg)) )
	{	write("现在没有这个玩家。\n");
		return 1;
	}
	
	write("指令格式：invite | yaoqing < 玩家id > \n");
	return 1;
}

void pos_leave(object me)
{	
	tell_object(me,"进错房间了，你的私房不是这里。\n");
        me->move(DDR+"clhoulang1");
        tell_object(this_object(),me->query("name") + "被请出了房间。\n");
        return;
}

void other_leave(object me)
{	
	tell_object(me,"你并不受这里主人的欢迎，还是快走吧。\n");
        me->move(DDR+"clhoulang1");
        tell_object(this_object(),me->query("name") + "被请出了房间。\n");
        return;
}

int do_nofight(string arg)
{
	object me = this_player();
	
	if ( !stringp(me->query("clbpos")) || me->query("clbpos")!="龙灵堂")
	{	write("你不是这里的主人，不能进行设置。\n");
		return 1;
	}        			
	
	write("此房间暂时设置为不允许战斗。\n");	
	set("no_fight",1);
	return 1;
}

int do_canfight(string arg)
{
	object me = this_player();
	
	if ( !stringp(me->query("clbpos")) || me->query("clbpos")!="龙灵堂")
	{	write("你不是这里的主人，不能进行设置。\n");
		return 1;
	}        			
		
	write("此房间恢复为允许战斗场所。\n");
	set("no_fight",0);
	return 1;
}

int do_modify(string arg)
{
	object me = this_player();
		
	if ( !stringp(me->query("clbpos")) || me->query("clbpos")!="龙灵堂")
	{	write("你不是这里的主人，不能进行描述设置。\n");
		return 1;
	}       

	if ( ! arg )
	{	write("此命令可以用来设置房间的描述。\n");
		write("指令格式为：modify <描述> \n");
		return 1;
	}
	
	arg = arg + "\n";
	set("long",arg);
	if (!write_file(SIFANG,arg,1))
		write("文件保存失败！请立刻于巫师联系。\n");
	else
		write("设置成功。\n");
	
	return 1;
}
	