// // Define the PAC script as a string
// const pacScript = `
// function FindProxyForURL(url, host) {
//   if (shExpMatch(host, "*x.com") ||
//       shExpMatch(host, "*twitter.com") ||
//       shExpMatch(host, "*twimg.com") ||
//       shExpMatch(host, "*whatismyip.com")) {
//     return "PROXY 129.146.172.227:3128"";
//   }
//   return "DIRECT";
// }
// `;

// // Set the proxy configuration
// function setProxy() {
//   const config = {
//     mode: "pac_script",
//     pacScript: {
//       data: pacScript
//     }
//   };

//   chrome.proxy.settings.set(
//     { value: config, scope: "regular" },
//     () => {
//       if (chrome.runtime.lastError) {
//         console.error("Error setting proxy:", chrome.runtime.lastError);
//       } else {
//         console.log("Proxy settings applied successfully.");
//       }
//     }
//   );
// }

// // Apply proxy settings when the extension starts
// setProxy();

/*

      "*.x.com",
      "*.twitter.com"

      
      */

// Define the proxy server details
const proxyServer = {
  scheme: "http", // or "https", "socks5", etc.
  host: "129.146.172.227",
  port: 3128
};

// PAC script as a string
const pacScript = `
  function FindProxyForURL(url, host) {
    // List of websites to proxy (use hostnames or wildcards)
    const proxySites = [
      "*.twitter.com",
      "*.x.com",
      "*.twimg.com",
      "*.whatismyip.com"
    ];

    // Check if the host matches any proxySites
    for (let site of proxySites) {
      console.log("Evaluating host:", host, site, shExpMatch(host, site));
      if (shExpMatch(host, site)) {
        return "PROXY ${proxyServer.host}:${proxyServer.port}";
      }
    }

    // Default to direct connection for all other sites
    return "DIRECT";
  }
`;

// Configure the proxy settings with the PAC script
const config = {
  mode: "pac_script",
  pacScript: {
    data: pacScript
  }
};

// Set the proxy settings
chrome.proxy.settings.set(
  { value: config, scope: "regular" },
  () => {
    if (chrome.runtime.lastError) {
      console.error("Error setting proxy:", chrome.runtime.lastError);
    } else {
      console.log("Proxy settings applied successfully");
    }
  }
);