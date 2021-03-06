// edemote.c emote编辑器
#include <ansi.h>
inherit ITEM;
inherit F_AUTOLOAD;
void setup()
{}
void create()
{
        set_name(HIC "表情动词编辑器" NOR, ({"emote editor", "editor"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "架");
                set("long", "这是一架看起来怪怪的仪器，上面贴着说明(help editor)。\n");
                set("value", 1);
                set("no_sell", 1);
        }
        setup();
}

int query_autoload()
{
        return 1;
}

void init()
{
        add_action("do_help", "help");
        if (environment() == this_player())
        {
                add_action("do_edemote", "edemote");
                add_action("do_cpemote", "cpemote");
                add_action("do_rnemote", "rnemote");
        }
}

int do_help(string arg)
{
        if (! arg || ! id(arg))
                return notify_fail("你要看什么帮助？\n");
        write (@HELP
关于表情动词编辑器的说明：

edemote [-d] [-p] verb
该命令用于编辑，显示，删除一个表情动词。其中verb是表情动词，
如果使用了-d参数则将删除该动词，如果使用了-p参数将显示该表
情动词具体的表情描述信息。如果编辑的表情动词原先是存在的，
则在编辑的时候可以直接输入"." 以保留原有的相应条目。

cpemote emote1 emote2
该命令可以将第一个表情动词的描述复制成第二个动词的描述。复
制的时候原先必须没有第二个动词的描述，复制以后第一个动词的
描述仍然存在，即将有两个独立但是描述相同的表情动词。

rnemote emote1 emote2
该命令可以改掉一个表情动词的名字，但是描述不变化。

HELP );
        return 1;
}

int do_edemote(string arg)
{
         return "/cmds/wiz/edemote"->main(this_player(), arg);
}

int do_cpemote(string arg)
{
        return "/cmds/imm/cpemote"->main(this_player(), arg);
}

int do_rnemote(string arg)
{
        return "/cmds/imm/rnemote"->main(this_player(), arg);
}
