// Code of ShenZhou
// board.c
// by Marz@XKX 11/09/96
// modified by Jay 6/2/97

inherit F_CLEAN_UP;

int main(object me)
{
        return notify_fail("请用help board查看留言版使用方法。\n");
}

int help()
{
        write(@HELP

客店及各个门派的留言版是玩家交留经验、心得的重要地方，
巫师也通过留言版发布ＭＵＤ的各种改动，因此一定要及时
查看。留言版指令在有留言版（Ｂｏａｒｄ，Ｒｅｐｏｒｔ
等）的地方才有效。

查看该留言版目录  ===> list

list                              查看所有留言目录。
list [id|ID]:[玩家ID]             查看该ID留言的目录。
list [name|Name]:[玩家名]         查看该玩家留言的目录。
list [last|Last]:[数目]           查看最后数条留言的目录。
list [noread|Noread]              查看自己未读过留言的目录。


阅读留言          ===> read

read [留言编号]                   阅读相应的留言。
read [留言编号].[回复编号]        阅读相应的留言的相应回复信息。
	

书写留言          ===> post

post <title>                      书写留言。
post <title> [-N|-n]              设定不可以回复，默认为允许。
	

回复留言          ===> re

re [留言编号].[回复标题]          对相应的留言进行回复。
如果没有回复标题，会自动设成{RE + 应该的留言编号}。


删除留言          ===> discard

discard [留言编号]                删除相应留言。
discard [留言编号].[回复编号]     删除相应留言中的相应回复。


新的board规定：
title不能超过四十个字符，即二十个汉字。


HELP
        );
        return 1;
}
