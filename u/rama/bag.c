/* /kungfu/class/movie/obj/pinang.c
** 贴身皮囊
** created by yujie
** created in 11/2001
*/

#include <ansi.h>


#define CAIPIAO "/kungfu/class/movie/obj/caipiao"
#define DATAFILE "/data/movie/caipiao/pinang"
#define CPSYS "/adm/single/cpsys"

inherit ITEM;
inherit F_SAVE;
inherit F_AUTOLOAD;


#include <inttostr.h>

int do_check(string);
int do_getout(string);
int do_putin(string);


void create()
{
	
        set_name(YEL"贴身皮囊"NOR, ({ "pi nang","nang" }));
        set_weight(10);
        set("long","这是一个装福利彩票的皮囊。\n你可以用check指令来查看皮囊里的彩票的号码。\ngetout和putin分别用来取指定号码的彩票和把彩票放进皮囊。\n");
        set("unit", "个");
        set("value", 0);
        set("no_drop",1);
        set("no_get",1);
        set("no_steal",1);
        set("no_give",1);
        
        setup();      
}

int query_autoload() {return 1;}
/*
void save_data(object me , string include)
{
	int i;
	string own,name;
	string msg , *data ,newdata;
	
	name = me->query("id");
	newdata = "";
	if ( me->query("get_pinang"))
	{
		msg = read_file(DATAFILE);
		data = explode(msg,"*");
		
		for(i=0; i < sizeof(data) ;i++)
		{	
			if (sscanf(data[i],"%s-%s",own,include) != 2)
				tell_object(me,"数据出错，请尽快和巫师联系！\n");
	
			if (name == own)
				newdata = newdata + name + "-" + include +"*";
			else
				newdata = newdata + data[i] + "*";
		}
		write_file(DATAFILE,newdata,1);
		
	}
}
*/	
	
void init()
{
	object me;
	string name , msg ,*data , own, include;
	int i;
	
	
	me = this_player();
	
	if ( me->query("get_pinang"))
	{
		name = me->query("id");
		if (!query("owner"))	set("owner",name);
		msg = read_file(DATAFILE);
		data = explode(msg,"*");
		for (i=0; i<sizeof(data) ;i++)
		{	
			if (sscanf(data[i],"%s-%s",own,include) != 2)
				write("数据出错，请尽快和巫师联系！\n");
			
			if (name == own)
				set("include",include);
		}
	}
	
	if ( query("owner") == me->query("id"))
	{	
		add_action("do_check" , "check");
		add_action("do_getout" , "getout");
		add_action("do_putin" , "putin");
	}
}

int do_check(string arg)
{
	object me = this_player();
	string *nums , msg;
	int i;
		
	if ( stringp (query("include")))
	{	
		msg = query("include");
		CPSYS->save_data(me,msg);
		nums = explode(msg,"\n");
		msg = "";
		for(i=0 ; i<sizeof(nums) ;i++)
			msg = msg + nums[i] + "    ";
		if (sizeof(nums) == 0)
			msg = "现在皮囊里没有任何彩票。\n";
		else 
			msg = "现在皮囊里存有的彩票号码分别是：\n" + msg + "\n";
		
		write(msg);
		return 1;
	}
	write("现在皮囊里没有任何彩票。\n");
	return 1;
}

int do_getout(string arg)
{
	object me = this_player();
	string *nums , msg ,newmsg;
	int num ,i ,got;
	object cp;
	
	if (!arg)
		return notify_fail("指令格式：getout <彩票号码>\n");
		
	if ( sscanf(arg,"%d",num)!= 1)
		return notify_fail("指令格式：getout <彩票号码>\n");
		
	msg = tostring(num);
	newmsg = "";
	got = 0;
	
	if( !stringp(query("include")) )
	{	write("皮囊里没有任何彩票。\n");
		return 1;
	}
	
	nums = explode(query("include"),"\n");
	for(i=0 ; i<sizeof(nums) ;i++)
	{	if(msg == nums[i])
		{	tell_room(environment(me),me->name()+"从皮囊从取出一张福利彩票。\n",me);
			write("你从皮囊里取出一张号码为："+HIW+msg+NOR+" 的福利彩票。\n");
			cp = new(CAIPIAO);
			cp->set("number",num);
			cp->move(me);
			got = 1;
		}
		else 
			newmsg = newmsg + nums[i] + "\n";
	}
			
	set("include",newmsg);
		
	if(got == 1)
	{	CPSYS->save_data(me,newmsg);
		return 1;	
	}
			
	if( sizeof(nums) == 0)
	{	write("现在皮囊里没有任何彩票。\n");
		return 1;
	}
	write("现在皮囊里没有这个号码的彩票，请用check查询皮囊里现有的彩票号码。\n");
	return 1;
}

int do_putin(string arg)
{
	object cp ,me = this_player();
	string *nums , msg ;
	int num ,i ,j;
	
	if (!arg)
		return notify_fail("你要把什么放进皮囊。\n");
	
	if ((arg != "caipiao") && (arg != "lottery") )
		return notify_fail("你只能把彩票放进皮囊。\n");
		
	if (!present("caipiao",me) )
		return notify_fail("你身上没有彩票。\n");
		
	i = 0;
	j = 0;
	
	while (objectp(present("caipiao",me)))
	{	cp = present("caipiao",me);
		if (base_name(cp) == CAIPIAO )
		{
		if ( num = cp->query("number"))
		{	
			msg = tostring(num)+"\n";
			add("include",msg);
                        CPSYS->save_data(me,query("include"));
		}
		else
			i++;
		destruct(cp);
		j++;
		}
	}
	
	j = j - i;
	write("你把身上的"+chinese_number(j)+"张彩票都放进了皮囊里。\n");
	tell_room(environment(me),me->name()+"把身上的福利彩票都放进了皮囊里。\n",me);
	if (i > 0)
		write("其中有"+chinese_number(i)+"张是废票，你随手扔掉了。\n");
	
	return 1;
}

