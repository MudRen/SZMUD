
#include <room.h>
#include <localtime.h>
#include <ansi.h>
 
inherit ROOM;

int playing = 0; 
 
void reset();

string *song;
string *qmar = ({
HIY"亲密爱人\n\n"NOR,

HIY"今夜还吹着风 想起你好温柔\n"NOR,
HIY"有你的日子分外的轻松\n"NOR,
HIY"也许是无影踪 只是想你太浓\n"NOR,
HIY"怎么会无时无刻把你梦\n"NOR,
HIY"爱的路上有你 我并不寂寞\n"NOR,
HIY"你对我那么的好 这次真的不同\n"NOR,
HIY"也许我应该好好把你拥有\n"NOR,
HIY"就像你一直在为我守候\n"NOR,
HIY"亲爱的人 亲密的爱人\n"NOR,
HIY"谢谢你这么长的时间陪着我\n"NOR,
HIY"亲爱的人 亲密的爱人\n"NOR,
HIY"这是我一生中最兴奋的时分\n"NOR,
});

string *xzdn = ({

HIG"常常的想，现在的你，就在我身边露出笑脸  \n"NOR,
HIG"可是，可是我，却搞不清，你离我是近还是远\n"NOR,
HIG"但我仍然，仍然相信，你和我今生一定有缘\n"NOR,
HIG"于是我就让，你看看我，一往情深的双眼\n"NOR,

HIG"书上说有情人千里能共婵娟，\n"NOR,
HIG"可是我现在只想把你手儿牵，\n"NOR,
HIG"听说过许多山盟海誓的表演\n"NOR,
HIG"忽然想看看你，曾经纯真的笑脸\n\n"NOR,

HIG"常常的想，现在的你，就在我身边露出笑脸  \n\n"NOR,

HIG"书上说有情人千里能共婵娟，\n"NOR,
HIG"可是我现在只想把你手儿牵，\n"NOR,
HIG"听说过许多山盟海誓的表演\n"NOR,
HIG"忽然想看看你，曾经纯真的笑脸\n"NOR,
HIG"常常的想，现在的你，就在我身边露出笑脸  \n\n"NOR,
});

string *zshyn = ({
    
HIG"    至少还有你 \n\n"NOR,                             

HIG"    我怕来不及 我要抱着你 \n"NOR,
HIG"    直到感觉你的皱纹 有了岁月的痕迹\n"NOR,
HIG"    直到肯定你是真的 \n"NOR,
HIG"    直到失去力气 为了你 我愿意 \n"NOR,
HIG"    动也不能动 也要看着你 \n"NOR,
HIG"    直到感觉你的发线 有了白雪的痕迹 \n"NOR,
HIG"    直到视线变得模糊 \n"NOR,
HIG"    直到不能呼吸 让我们形影不离 \n"NOR,
HIG"    如果 全世界我也可以放弃 \n"NOR,
HIG"    至少还有你值得我去珍惜 而你在这里 \n"NOR,
HIG"    就是生命的奇迹 \n"NOR,

HIG"    也许 全世界我也可以忘记 \n"NOR,
HIG"    就是不愿意失去你的消息 \n"NOR,
HIG"    你掌心的痣 我总记得在那里 \n"NOR,

HIG"    我们好不容易 我们身不由己 \n"NOR,
HIG"    我怕时间太快 不够将你看仔细\n"NOR,
HIG"    我怕时间太慢 \n"NOR,

HIG"    日夜担心失去你 \n"NOR,
HIG"    恨不得一夜之间白头 永不分离 \n"NOR,

HIG"    如果 全世界我也可以放弃 \n"NOR,
HIG"    至少还有你值得我去珍惜 \n"NOR,
HIG"    而你在这里 就是生命的奇迹 \n"NOR,

HIG"    也许 全世界我也可以忘记 \n"NOR,
HIG"    就是不愿意失去你的消息 \n"NOR,
HIG"    你掌心的痣 我总记得在那里\n"NOR
});

string *woman = ({    
HIG"    When you're in love with a beautiful woman　 \n"NOR,
HIG"    It's hard  \n"NOR,
HIG"    When you're in love with a beautiful woman \n"NOR,
HIG"    You know it's hard  \n"NOR,
HIG"    Everybody wants her,　Everybody loves her   \n"NOR,
HIG"    Everybody wants to take your baby home \n"NOR,
    
HIG"    When you're in love with a beautiful woman　 \n"NOR,
HIG"    You watch your friends \n"NOR,
HIG"    When you're in love with a beautiful woman　 \n"NOR,
HIG"    It never ends\n"NOR,
HIG"    you know that is crazy\n"NOR,
HIG"    you want to trust her\n"NOR,
HIG"    there is somebody hangs up when you answer the phone\n"NOR,

HIG"    When you're in love with a beautiful woman　 \n"NOR,
HIG"    You got it alone  \n"NOR,
HIG"    Maybe just an ego problem \n"NOR,    
HIG"    Problem is I've been fooled before  \n"NOR,
HIG"    But fair weather friends and faint hearted lovers  \n"NOR,
HIG"    And everytime it happens　It just convinces me more  \n"NOR,
HIG"    When you're in love with a beautiful woman　 \n"NOR,
HIG"    You watch her eyes  \n"NOR,
HIG"    When you're in love with a beautiful woman　 \n"NOR,
HIG"    You look for lies  \n"NOR,
HIG"    Everybody tempts her　\n"NOR,
HIG"    Everybody tells her  \n"NOR,
HIG"    When you're in love with a beautiful woman　 \n"NOR,
HIG"    You got it alone  \n"NOR
});

string *qfdy = ({
        
CYN"    情非得已\n\n"NOR,
    
CYN"    难以忘记初次见你  \n"NOR,
CYN"    一双迷人的眼睛  \n"NOR,
CYN"    在我脑海里  你的身影  挥散不去  \n"NOR,
CYN"    握你的双手感觉你的温柔 \n"NOR,
CYN"    真的有点透不过气\n"NOR,
CYN"    你的天真  我想珍惜  \n"NOR,
CYN"    看到你受委屈  我会伤心\n"NOR,
CYN"    只怕我自己会爱上你 \n"NOR,
CYN"    不敢让自己靠的太近 \n"NOR,
CYN"    怕我没什么能够给你  \n"NOR,
CYN"    爱你也需要很大的勇气 \n"NOR,
CYN"    只怕我自己会爱上你 \n"NOR,
CYN"    或许有天会情不自禁 \n"NOR,
CYN"    想念只让自己苦了自己 \n"NOR,
CYN"    爱上你是我情非得已 \n\n"NOR,

CYN"    什么原因  我竟然又会遇见你 \n"NOR,
CYN"    我真的真的不愿意  \n"NOR,
CYN"    就这样陷入爱的陷阱\n"NOR,
CYN"    只怕我自己会爱上你 \n"NOR,
CYN"    不敢让自己靠的太近 \n"NOR,
CYN"    怕我没什么能够给你  \n"NOR,
CYN"    爱你也需要很大的勇气 \n"NOR,
CYN"    只怕我自己会爱上你 \n"NOR,
CYN"    或许有天会情不自禁 \n"NOR,
CYN"    想念只让自己苦了自己 \n"NOR,
CYN"    爱上你是我情非得已 \n\n"NOR,
CYN"    爱上你是我情非得已 \n\n"NOR
});
    
string *everything = ({
    
HIB"  (Everything I Do) I Do It For You \n\n"NOR,

HIB"  Look into my eyes - you will see\n"NOR,
HIB"  What you mean to me\n"NOR,
HIB"  Search your heart - search your soul\n"NOR,
HIB"  And when you find me there you'll search no more\n"NOR,
HIB"  Don't tell me it's not worth tryin' for\n"NOR,
HIB"  You can't tell me it's not worth dyin' for\n"NOR,
HIB"  You know it's true\n"NOR,
HIB"  Everything I do - I do it for you\n"NOR,

HIB"  Look into my heart - you will find\n"NOR,
HIB"  There's nothin' there to hide\n"NOR,
HIB"  Take me as I am - take my life\n"NOR,
HIB"  I would give it all I would sacrifice\n"NOR,
HIB"  Don't tell me it's not worth fightin' for\n"NOR,
HIB"  I can't help it there's nothin' I want more\n"NOR,
HIB"  Ya know it's true\n"NOR,
HIB"  Everything I do - I do it for you\n"NOR,

HIB"  There's no love - like your love\n"NOR,
HIB"  And no other - could give more love\n"NOR,
HIB"  There's nowhere - unless you're there\n"NOR,
HIB"  All the time - all the way\n"NOR,

HIB"  Don't tell me it's not worth tryin' for\n"NOR,
HIB"  I can't help it there's nothin' I want more\n"NOR,
HIB"  I would fight for you - I'd lie for you\n"NOR,
HIB"  Walk the wire for you - Ya I'd die for you\n"NOR,

HIB"  Ya know it's true\n"NOR,
HIB"  Everything I do - I do it for you    \n"NOR
}); 
 
string *liuxing = ({
HIG"  我想知道 流星能飞多久 它的美丽是否\n"NOR,
HIG"  值得去寻求 夜空的花 散落在你身后\n"NOR,
HIG"  幸福了我很久 值我去等候\n\n"NOR,

HIG"  于是我心狂奔 从黄昏到清晨 不能再承受\n"NOR,
HIG"  情愿坠落在你手中 羽化成黑夜的彩虹 蜕变成月光的清风\n\n"NOR,

HIG"  成月光的清风 我纵身跳 跳进你的河流 一直游到尽头\n"NOR,
HIG"  那里多自由 我许个愿 我许个愿保佑 让我的心凝个\n\n"NOR,

HIG"  在最美的时候 情愿坠落在你手中 羽化成黑夜的彩虹\n"NOR,
HIG"  情愿不再见明媚的天 不再见明媚的天 幸福\n\n"NOR,

HIG"  跳进你的河流 一直游到尽头 跳进你的河 我许个愿保佑\n"NOR,
HIG"  在最美的时候 我许的愿 我想知道 流星能飞多久\n"NOR, 
HIG"  幸福了我很久\n\n\n\n"NOR
});
 
string *sadness = ({ 

 HIG"你怎么舍得我难过\n\n"NOR, 


HIG"对你的思念 是一天又一天\n"NOR,
HIG"孤单的我还是没有改变\n"NOR,
HIG"美丽的梦 何时才能出现\n"NOR,
HIG"亲爱的你 好想再见你一面\n\n"NOR,

HIG"秋天的风 一阵阵的吹过\n"NOR,
HIG"想起了去年的这个时候\n"NOR,
HIG"你的心  到底在想些什么\n"NOR,
HIG"为什么留下这个结局让我承受\n\n"NOR,

HIG"最爱你的人是我 你怎么舍得我难过\n"NOR,
HIG"在我最需要你的时候 没有说一句话就走\n"NOR,

HIG"最爱你的人是我 你怎么舍得我难过\n"NOR,
HIG"对你付出了这么多 你却没有感动过 \n"NOR
});

string *weiyi = ({
    
HIG"如今才是唯一\n\n"NOR,
 
HIG"有一些爱情 难得会拥有 美丽的时候\n"NOR,
HIG"曾经他爱我 如今仍爱我 可是更爱自由\n"NOR,
HIG"有更多爱情 与更多籍口 难轻易回头\n"NOR,
HIG"什么叫天长 什么叫地久 此生够不够\n\n"NOR,
 
HIG"千山以外 沧海自由 何处是以后\n"NOR,
HIG"需不需要承诺 最难测的承诺 换取安全的感受\n\n"NOR,
 
HIG"眼中看见你 睡梦中分离 转身春已去\n"NOR,
HIG"人生的漂移 如春去秋来 转身又一季\n"NOR,
HIG"丛未曾为你 活在孤单里 只怕承受不起\n"NOR,
HIG"想忘记过去 却不知将来 还是要相偎依\n\n"NOR,
 
HIG"多少往事风尘如烟天长地久\n"NOR,
HIG"终会有个梦醒的时候\n"NOR,
HIG"多少海市蜃楼已成季节不朽\n"NOR,
HIG"终会等到天明的宇宙\n\n"NOR,
 
HIG"是过客的我 与过客的你 在编织回忆\n"NOR,
HIG"只愿意分离 不愿意忘记 总算不容易\n"NOR,
HIG"曾经过沧海 不需要山盟 还是相聚一起\n"NOR,
HIG"不要说过去 不要问将来 此刻终将回忆\n\n"NOR,
 
HIG"不忘记过去 不相信将来 如今才是唯一\n"NOR });

string *yijianmei = ({
HIG"\n      一 剪 梅\n"NOR, 
HIG"            -- 李清照\n\n"NOR,

HIG"    红藕香残玉潭秋\n"NOR,
HIG"    轻解罗裳 独上兰舟\n"NOR,
HIG"    云中谁寄锦书来\n"NOR,
HIG"    燕字回时 月满西楼 \n\n"NOR,

HIG"    花自飘零水自流\n"NOR,
HIG"    一种相思 两处闲愁\n"NOR,
HIG"    此情无计可消除\n"NOR,
HIG"    才下眉头,却上心头\n"NOR});


string *unbreak = ({
HIC"\nUn-break my heart\n\n\n"NOR,
HIC"Don't leave me in all this pain \n"NOR,
HIC"Don't leave me out in the rain \n"NOR,
HIC"Come back and bring back my smile \n"NOR,
HIC"Come and take these tears away \n"NOR,
HIC"I need your arms to hold me now \n"NOR,
HIC"The nights are so unkind \n"NOR,
HIC"Bring back those nights when I held you beside me \n\n"NOR,

HIC"Un-break my heart \n"NOR,
HIC"Say you'll love me again \n"NOR,
HIC"Undo this hurt you caused \n"NOR,
HIC"When you walked out the door \n"NOR,
HIC"And walked outta my life \n"NOR,
HIC"Un-cry these tears \n"NOR,
HIC"I cried so many nights \n"NOR,
HIC"Un-break my heart \n"NOR,
HIC"My heart \n\n"NOR,

HIC"Take back that sad word good-bye \n"NOR,
HIC"Bring back the joy to my life \n"NOR,
HIC"Don't leave me here with these tears \n"NOR,
HIC"Come and kiss this pain away \n"NOR,
HIC"I can't forget the day you left \n"NOR,
HIC"Time is so unkind \n"NOR,
HIC"And life is so cruel without you here beside me \n\n"NOR,

HIC"Un-break my heart \n"NOR,
HIC"Say you'll love me again \n"NOR,
HIC"Undo this hurt you caused \n"NOR,
HIC"When you walked out the door \n"NOR,
HIC"And walked outta my life \n"NOR,
HIC"Un-cry these tears \n"NOR,
HIC"I cried so many nights \n"NOR,
HIC"Un-break my heart \n"NOR,
HIC"My heart \n"NOR,

HIC"Don't leave me in all this pain \n"NOR,
HIC"Don't leave me out in the rain \n"NOR,
HIC"Bring back the nights when I held you beside me \n"NOR,

HIC"Un-break my heart \n"NOR,
HIC"Say you'll love me again \n"NOR,
HIC"Undo this hurt you caused \n"NOR,
HIC"When you walked out the door \n"NOR,
HIC"And walked outta my life \n"NOR,
HIC"Un-cry these tears \n"NOR,
HIC"I cried so many, many nights \n"NOR,
HIC"Un-break my \n\n"NOR,

HIC"Un-break my heart \n"NOR,
HIC"Come back and say you love me \n"NOR,
HIC"Un-break my heart \n"NOR,
HIC"Sweet darlin' \n"NOR,
HIC"Without you I just can't go on \n"NOR,
HIC"Can't go on\n\n"NOR
});

string *imagine =
({ 
MAG"\nImagine\n\n\n"NOR,
MAG"Imagine there's no heaven,\n"NOR,
MAG"it's easy if you try,\n"NOR,
MAG"no hell below us,\n"NOR,
MAG"above us only sky,\n"NOR,
MAG"Imagine all the people,\n"NOR,
MAG"living for today.\n\n"NOR,

MAG"Imagine there's no country,\n"NOR,
MAG"it isn't hard to do,\n"NOR,
MAG"nothing to kill or die for,\n"NOR,
MAG"and no religion too,\n"NOR,
MAG"Imagine all the people,\n"NOR,
MAG"living life in peace.\n\n"NOR,

MAG"You may say I'm a dreamer,\n"NOR,
MAG"but I'm not the only one,\n"NOR,
MAG"I hope someday you'll join us,\n"NOR,
MAG"and the world will be as one.\n\n"NOR,

MAG"Imagine no possession,\n"NOR,
MAG"I wonder if you can,\n"NOR,
MAG"no need for greed or hunger,\n"NOR,
MAG"a brotherhood of man,\n"NOR,
MAG"Imagine all the people,\n"NOR,
MAG"sharing all the world.\n\n"NOR,

MAG"You may say I'm a dreamer,\n"NOR, 
MAG"but I'm not the only one,\n"NOR, 
MAG"I hope someday you'll join us,\n"NOR,
MAG"and the world will live as one\n"NOR 
}); 

void create()
{
    mixed *local = localtime( time()*60 );
    set( "short", MAG"音乐小屋"NOR );
    set( "long", CYN"蓝蓝的，透明的，拱形玻璃屋顶上布满了一闪一闪的小灯串，\n" +
                    "象是千百颗眨眼的小星星正偷偷地窥视着地上的情侣。遥远的地方\n" +
                    "轻轻地传来了一阵阵的(play)歌声。\n"NOR );
    set( "cost", 0 );
    set("no_fight", "1"); 
    set("exits", ([ 
                "down" : "/p/fystreet/room/mariner_room",
                "up" : "/u/mariner/yekong",
		])); 
    set("no_steal", 1); 
    set("no_sleep_room", 1); 
    if ( local[LT_HOUR] < 5 )
        set( "exits/enter", "/u/mariner/musicroom" );
    setup();
}

void init()
{
    add_action( "play", "play" );
    add_action( "List", "list" );
    if ( this_player()->query( "id" ) == "mariner" )
        add_action( "stop", "stop" );
}

int stop( string arg )
{
    if ( playing )
    {
        remove_call_out( "PlaySong" );
        playing = 0;
    }    
    return 1;
}

int List( string arg )
{
    write( HIB"imagine -- Imagine by John Lennon.\n" );
    write( "unbreak -- Un-break my heart\n" );
    write( "yijianmei -- 一剪梅*李清照\n" );
    write( "liuxing -- 流星花园\n" );
    write( "weiyi -- 唯一\n" );
    write( "sadness -- 你怎么舍得我难过\n" );
    write( "qfdy -- 情非得已\n" );
    write( "woman -- When you in love with a beautiful woman\n" );
    write( "zshyn -- 至少还有你\n" );
    write( "xzdn -- 笑脸\n" );
    write( HIY"qmar -- 亲密爱人\n"NOR );
    write( HIB"everything -- everything I do, I do it for you\n"NOR );
    return 1;
}

int play( string arg )
{
    if ( !arg ) 
        return notify_fail("这里歌曲很多，你想听哪首呢? 请用（list）选择你要听的曲目\n" );
    if ( playing ) 
        return notify_fail( "Music is playing.\n" );
    switch ( arg )
    {
    case "imagine":
        song = imagine;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    case "unbreak":
        song = unbreak;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    case "yijianmei":
        song = yijianmei;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    case "weiyi":
        song = weiyi;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    case "liuxing":
        song = liuxing;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    case "sadness":
        song = sadness; 
        call_out( "PlaySong", 1, 0 ); 
        playing = 1;
        break;
    case "everything":
        song = everything;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    case "qfdy": 
        song = qfdy;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    case "woman":
        song = woman;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;        
    case "zshyn":
        song = zshyn;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;   
    case "xzdn":
        song = xzdn;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;              
    case "qmar":
        song = qmar;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    default:
        write( "We do not have this song.\n" );
        break;
    }
    return 1;
}

void PlaySong( int i )
{
    if ( i < sizeof ( song ) )
    {
        tell_room( this_object(), song[ i ] );
        i ++;
        remove_call_out( "PlaySong" );
        call_out( "PlaySong", 2, i );
    }
    else 
        playing = 0;    
}

