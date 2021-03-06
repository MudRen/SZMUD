// giveall.c
//BY cnnetgame.com's WFoxd 2000-9-15
/*请不要连续使用本命令，特别是在人多的时候，会给系统带来很大负担*/

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string what)
{
    object ob, *ob_list, ob1;
    int i;
    string str;
    
    if(!what) return notify_fail("指令格式 giveall 物品路径\n");
    
    if( sscanf(what, "%*s.c") != 1) return notify_fail("路径不合法，无法找到物品。\n");
    
    if( file_size(what) < 0 )
		return notify_fail("没有这个档案(" + what + ")。\n");    
    
    seteuid(getuid());

    ob_list = users();

    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        ob1 = new(what);
        ob1 -> move(ob); 
        tell_object(ob, HIW "\n\n忽然从极高极远的天空中极速降下一只浑身烈焰的"HIR"火凤"HIW"，周身闪耀七彩光芒。\n" NOR);
        tell_object(ob, HIC "它爪下似乎抓着什么东西，突然"HIR"火凤"HIW"松开脚爪，有个东西直向你掉落下来。\n" NOR);
        tell_object(ob, HIG "你猛一提气纵身一跃丈高将此物抓在手中，又潇洒的飘落地面。\n\n" NOR);
        
    }
    str = sprintf("共有 %d 位玩家得到了%s。\n", sizeof(ob_list), what->query("name"));    
    me->start_more(str);
    return 1;
}

int help(object me)
{
        write(@HELP
指令格式：giveall 物品路径

给在线的所有玩家一件物品。
HELP
        );
        return 1;
}
