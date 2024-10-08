#pragma once

#include "ven-window.h"

// std lib headers
#include <string>
#include <vector>

namespace Ven {

struct SwapChainSupportDetails {
  VkSurfaceCapabilitiesKHR capabilities;
  std::vector<VkSurfaceFormatKHR> formats;
  std::vector<VkPresentModeKHR> presentModes;
};

struct QueueFamilyIndices {
  uint32_t graphicsFamily;
  uint32_t presentFamily;
  bool graphicsFamilyHasValue = false;
  bool presentFamilyHasValue = false;
  bool IsComplete() { return graphicsFamilyHasValue && presentFamilyHasValue; }
};

class VenDevice {
 public:
#ifdef NDEBUG
  const bool enableValidationLayers = false;
#else
  const bool enableValidationLayers = true;
#endif

  explicit VenDevice(VenWindow &window);
  ~VenDevice();

  // Not copyable or movable
  VenDevice(const VenDevice &) = delete;
  void operator=(const VenDevice &) = delete;
  VenDevice(VenDevice &&) = delete;
  VenDevice &operator=(VenDevice &&) = delete;

  VkCommandPool GetCommandPool() { return commandPool; }
  VkDevice Device() { return device_; }
  VkSurfaceKHR Surface() { return surface_; }
  VkQueue GraphicsQueue() { return graphicsQueue_; }
  VkQueue PresentQueue() { return presentQueue_; }

  SwapChainSupportDetails GetSwapChainSupport() { return QuerySwapChainSupport(physicalDevice); }
  uint32_t FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags flags);
  QueueFamilyIndices FindPhysicalQueueFamilies() { return FindQueueFamilies(physicalDevice); }
  VkFormat FindSupportedFormat(
      const std::vector<VkFormat> &candidates, VkImageTiling tiling, VkFormatFeatureFlags features);

  // Buffer Helper Functions
  void CreateBuffer(
      VkDeviceSize size,
      VkBufferUsageFlags usage,
      VkMemoryPropertyFlags flags,
      VkBuffer &buffer,
      VkDeviceMemory &bufferMemory);
  VkCommandBuffer BeginSingleTimeCommands();
  void EndSingleTimeCommands(VkCommandBuffer commandBuffer);
  void CopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
  void CopyBufferToImage(
      VkBuffer buffer, VkImage image, uint32_t width, uint32_t height, uint32_t layerCount);

  void CreateImageWithInfo(
      const VkImageCreateInfo &imageInfo,
      VkMemoryPropertyFlags flags,
      VkImage &image,
      VkDeviceMemory &imageMemory);

  VkPhysicalDeviceProperties properties;

 private:
  void CreateInstance();
  void SetupDebugMessenger();
  void CreateSurface();
  void PickPhysicalDevice();
  void CreateLogicalDevice();
  void CreateCommandPool();

  // helper functions
  bool IsDeviceSuitable(VkPhysicalDevice device);
  std::vector<const char *> GetRequiredExtensions();
  bool CheckValidationLayerSupport();
  QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
  void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);
  void HasGlfwRequiredInstanceExtensions();
  bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
  SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);

  VkInstance instance;
  VkDebugUtilsMessengerEXT debugMessenger;
  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  VenWindow &window;
  VkCommandPool commandPool;

  VkDevice device_;
  VkSurfaceKHR surface_;
  VkQueue graphicsQueue_;
  VkQueue presentQueue_;

  const std::vector<const char *> validationLayers = {"VK_LAYER_KHRONOS_validation"};
  const std::vector<const char *> deviceExtensions = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
};

}  // namespace Ven