/* /kungfu/class/movie/obj/caipiao.c
** 福利彩票
** created by yujie
** created in 11/2001
*/

inherit ITEM;

#include <ansi.h>
#include <inttostr.h>

string look_it();

void create()
{
        set_name("福利彩票", ({ "caipiao","lottery" }));
        set_weight(10);
        set("long",(:look_it:));
        set("unit", "张");
        set("value", 0);
              
}

string look_it()
{
	int num;
	
	num = query("number");
	if (intp(num)&& num != 0)
		return "这是扬州彩票行发行的福利彩票。\n这张彩票的号码是："+HIW+tostring(num)+NOR+"\n福利彩票每星期开一次奖，详细消息可以去彩票行查询。\n祝你中奖！！\n";
	
	return "这是一张废彩票。\n";
}
		
